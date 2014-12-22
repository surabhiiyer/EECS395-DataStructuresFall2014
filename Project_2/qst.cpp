//
//  qst.cpp
//  DS_Proj2_v4
//
//  Created by Surabhi Ravishankar  on 11/9/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//
#include "qst.h"
#include <string>
#include <iostream>

using namespace std;

qst::qst(){
	internal_node = new qinternalnode(0,16384,0, 16384);
}

void qst::makenull(){
	qst();
}

bool qst::isEmpty(){
	if(internal_node->nw == NULL && internal_node->ne == NULL && internal_node->sw == NULL && internal_node->se == NULL)
		return true;
	else
		return false;
}

// Debug uses a recursive call to find the internal node.

void qst::debug(qnode* node){
    if (node == NULL){
        cout<<"E";
        return;
    }
    visitNode(node);
    if (node->internal == true){
        debug(node->nw);
        debug(node->ne);
        debug(node->sw);
        debug(node->se);
    }
    else{
        return;
    }
    
}
/*  Uses the condition that if a node is a leaf node it prints E and if an leaf is an Internal node it prints I
    it prints the X and Y coordinates along with I or E and the City Name.
 */

void qst::visitNode(qnode* node){
    if (node == NULL)
    {
        cout<<"E";
    }
    else
    {
        if(node->internal == true)
        {
            cout<<"I";
        }
        if(node->internal == false && node == NULL)
        {
            cout<<"E";
        }
        else
        {
            cout<<node->x<<","<<node->y<<node->cityName<<"|";
        }
    }
}

/*  The Radius function is used to find coordinates or cities that are within the radius distance as specified
    It uses the area of a circle formula to find the cities that lie in that range. x(curr - given)^2 + y(curr - given) < = radius^2
 */
void qst::radius_func(qnode* node, int x1, int y1, int radius){
    
    if (node == NULL)	{}
    else if(node->internal == true)	{}
    else{
        if ((((node->x - x1) * (node->x - x1)) + ((node->y - y1) * (node->y - y1))) <= radius * radius)
            cout<<"Finding cities in the Given Radius ----- "<<"City: "<<node->cityName<<" X: "<<node->x<<" Y: "<<node->y<<endl;
    }
}

/*  The radius_func is called in the search function which in turn is implemented recursively.*/
void qst::search(qnode* node, int x1, int y1, int radius){
    if (node == NULL){
        return;
    }
    radius_func(node, x1, y1, radius);
    search(node->nw, x1, y1, radius);
    search(node->ne, x1, y1, radius);
    search(node->sw, x1, y1, radius);
    search(node->se, x1, y1, radius);
}

/* The find function is used to retrieve the city name when the user provides the input x and y coordinates */

qnode* qst::find(int x1, int y1)
{
    qnode* node;
    node = find(internal_node, x1, y1);
    return node;
}
qnode* qst::find(qnode* node, int x1, int y1){
    if (node == NULL)
    {
        return NULL;
    }
    qnode *node1;
    node1=findNode(node, x1, y1);
    if(node1==NULL)
    {
        node1=find(node->nw, x1, y1);
        
        if(node1==NULL)
        {
            node1=find(node->ne, x1, y1);
            
            if(node1==NULL)
            {
                node1=find(node->sw, x1, y1);
                if(node1==NULL)
                {
                    node1=find(node->se, x1, y1);
                }
                else
                {
                    return node1;
                    
                }
            }
            else
                return node1;
        }
        else
            return node1;
    }
    else
        return node1;
    return NULL;	
}

qnode*	qst::findNode(qnode* node, int x1, int y1){
    if (node == NULL){
        return NULL;
    }
    else if(node->internal == true){
        return NULL;
    }
    else{
        if ((node->x == x1) && (node->y == y1)){
            return node;
        }
        else{
            return NULL;
        }
    }
}

/*  This function establishes a range of values within which the coordinate can lie. it uses the min and max values of x and y coordinates that are provided
    The function essentially finds the point's location in the space, That is, NW, NE, SW, SE.
 */

string qst::location(qinternalnode* node, int x1, int y1){
	
    string location = "";
	
    //Establishing boundries
    
    int x_l = node-> x_max - node->x_min;
	int y_l = node-> y_max - node->y_min;

	int x_left = node-> x_min;
	int x_right = node-> x_max;
	int x_mid = node-> x_min + x_l/2;

	int y_up = node->y_min;
	int y_down = node->y_max;
	int y_mid = node->y_min + y_l/2;

	
	if ((x_left <= x1) && (x1 <= x_mid) && (y_up <= y1) && (y1 <= y_mid)){
			location = "nw";
			return location;
	}
	else if ((x_mid < x1) && (x1 <= x_right) && (y_up < y1) &&(y1 <= y_mid)){
			location = "ne";
			return location;
	}
	else if ((x_left < x1) && (x1 <= x_mid) && (y_mid < y1 ) &&(y1 <= y_down)){
			location = "sw";
			return location;
	}
	else{
			location = "se";
			return location;
	}
}

/* Algorithm for insertion 
 
    Using a recursive call, I divided the space into, 
    four parts NW, NE, SW, SE.

    Then find the point's location in the space, That is, NW, NE, SW, SE.
 
    If the coordinate is null 
        insert there else
 
    check if the coordinates match
 
    else
        keep the current node as root and insert the new node its new subtree

    The function also handles duplicate entries.
 */


/*  This follows function overloading. It finds the coordinates in space and
    returns the location -> NW, NE,  SW, SE 
    Based on this the insert function on the node is called.
*/

bool qst::insert(int x1, int y1, string name){
	bool rvalue = true;
	string orientation = location(internal_node, x1, y1);
	if(isEmpty() == true){
		if(orientation == "nw")
			internal_node->nw = new qleafnode(x1, y1, name, "nw");

		else if(orientation == "ne")
			internal_node->ne = new qleafnode(x1, y1, name, "ne");
		
		else if(orientation == "sw")
			internal_node->sw = new qleafnode(x1, y1, name, "sw");

		else if(orientation == "se")
			internal_node->se = new qleafnode(x1, y1, name, "se");

		internal_node->parent = NULL;
	}
	else
		rvalue = insert(internal_node, x1, y1,name);
	return rvalue;
}

bool qst::insert(qnode* node, int x1, int y1 , string name){

	bool flag_success = true;
	
	if(node->internal == true){

		qinternalnode* temp = dynamic_cast<qinternalnode*>(node);
		
        int x_l = temp->x_max - temp->x_min;
		int y_l = temp->y_max - temp->y_min;

		int x_left = temp->x_min;
		int x_right = temp->x_max;
		int x_mid = temp->x_min + x_l/2;

		int y_up = temp->y_min;
		int y_down = temp->y_max;
		int y_mid = temp->y_min + y_l/2;

		string orientation = location(temp, x1, y1);

        if(orientation == "nw"){
                    if(temp->nw==NULL){
                        temp->nw = new qleafnode(x1, y1, name, "nw");
                        temp->children ++;
                    }
                    else if (temp->nw->x == x1 && temp->nw->y == y1){
                        cout<<"DUPLICATE COORDINATES "<<temp->nw->x<<","<<temp->nw->y<<endl;
                        flag_success = false;
                        return flag_success;
                    }
                    else if(temp->nw->internal == true){
                        qinternalnode* new_temp = dynamic_cast<qinternalnode*>(temp);
                        insert(new_temp->nw, x1, y1, name);
                    }
                    else{
                        int x = temp->nw->x;
                        int y = temp->nw->y;
                        if(x_l > 5 && y_l > 5){
                            string city_name = temp->nw->cityName;
                            delete temp->nw;
                            temp->children --;
                            temp->nw = new qinternalnode(x_left, x_mid, y_up, y_mid);
                            temp->children ++;
                            insert(temp->nw, x, y, city_name);
                            insert(temp->nw, x1, y1, name);
                        }
            
                    }
            
            
                }
            else if(orientation == "ne"){
                    
                if(temp->ne == NULL){
                    temp->ne = new qleafnode(x1, y1,name, "ne");
                    temp->children ++;
                }
                else if (temp->ne->x == x1 && temp->ne->y == y1){
                    cout<<"DUPLICATE COORDINATES "<<temp->ne->x<<","<<temp->ne->y<<endl;
                    flag_success = false;
                    return flag_success;
                }
                else if(temp->ne->internal == true){
                    qinternalnode* new_temp =dynamic_cast<qinternalnode*>(temp);
                    insert(new_temp->ne, x1, y1, name);
                }
                else{
                    
                    int x = temp->ne->x;
                    int y = temp->ne->y;
                    if(x_l > 5 && y_l > 5){
                        string city_name = temp->ne->cityName;
                        delete temp->ne;
                        temp->children--;
                        temp->ne = new qinternalnode(x_mid, x_right, y_up, y_mid);
                        temp->children++;
                        insert(temp->ne, x, y, city_name);
                        insert(temp->ne, x1, y1, name);
                    }
                }
                }
        
        else if(orientation == "sw"){
                        if(temp->sw == NULL){
                        temp->sw = new qleafnode(x1, y1,name, "sw");
                        temp->children++;
                    }
                    else if (temp->sw->x == x1 && temp->sw->y == y1){
                        cout<<"DUPLICATE COORDINATES "<<temp->sw->x<<","<<temp->sw->y<<endl;
                        flag_success = false;
                        return flag_success;
                    }
                    else if(temp->sw->internal == true){
                        qinternalnode* new_temp =dynamic_cast<qinternalnode*>(temp);
                        
                        insert(new_temp->sw, x1, y1, name);
                    }
                    else
                    {
                        int x = temp->sw->x;
                        int y = temp->sw->y;
                        if(x_l > 5 && y_l > 5){
                            string city_name = temp->sw->cityName;
                            delete temp->sw;
                            temp->children--;
                            temp->sw = new qinternalnode(x_left, x_mid, y_mid, y_down);
                            temp->children++;
                            insert(temp->sw, x, y, city_name);
                            insert(temp->sw, x1, y1, name);
                        }
                    }
                }
                
        else if(orientation == "se")
        {
                if(temp->se == NULL){
                    temp->se = new qleafnode(x1, y1,name, "se");
                    temp->children++;
                }
                
                else if (temp->se->x == x1 && temp->se->y == y1){
                    cout<<"DUPLICATE COORDINATES "<<temp->se->x<<","<<temp->se->y<<endl;
                    flag_success = false;
                    return flag_success;
                }
                else if(temp->se->internal == true){
                    qinternalnode* new_temp =dynamic_cast<qinternalnode*>(temp);
                    insert(new_temp->se, x1, y1, name);
                }
                else{
                    
                    int x = temp->se->x;
                    int y = temp->se->y;
                    if(x_l > 5 && y_l > 5){
                        string city_name = temp->se->cityName;
                        delete temp->se;
                        temp->children--;
                        temp->se = new qinternalnode(x_mid, x_right, y_mid, y_down);
                        temp->children++;
                        insert(temp->se, x1, y1, name);
                        insert(temp->se, x, y, city_name);
                    }
                
                }
            }
    }
    return flag_success;
}


/*  Algorithm for removal
    
    1.  Locate the node N of PR quadtree that contains the
        record for the cityName. 
 
    2.  The Node is then marked as empty.
    
    3.  Next, the node's siblings are checked
            Then the node and its siblings are to be merged.
                codition for merging: If there is only one coordinate contained. 
                merge until the level where in 2 points are contained in the subtrees.
 
 */

/* The random function is called in order to handle the above listed 3 cases */

void qst::remove(qnode* node, int x1, int y1){
    
    if (isEmpty() == true){
        cout<<"EMPTY SET"<<endl;
        return;
    }
    if (node->internal == true){
        qinternalnode* temp = dynamic_cast<qinternalnode*>(node);
        string orientation = location(temp, x1, y1);
        
        if (orientation == "nw"){
            random_func(temp,node,temp->nw,x1,y1);
        }
        
        else if (orientation == "ne"){
            random_func(temp,node,temp->ne,x1,y1);
        }
        
        
        else if (orientation == "sw"){
            random_func(temp,node,temp->sw,x1,y1);
        }
        
        
        else if (orientation == "se"){
            random_func(temp,node,temp->se,x1,y1);
        }
        
    }
}

/* This removal function check if its an internal node or not. If it is an internal node, the remove function is called recursively */
/* If it is not an internal node, delete the node, and reduce the number of childern by 1 */
/* If the number of childern is 1, then the merging operation should take place -- random_child_func() is called */

void qst::random_func(qnode* temp,qnode* node,qnode* nodedir, int x1, int y1){
    if(nodedir != NULL){
        if(nodedir->internal == true)
            remove(nodedir, x1, y1);
        if(nodedir->internal == false){
            if(nodedir->x == x1 && nodedir->y == y1){
                delete nodedir;
                temp->children--;
                nodedir = NULL;
            }
            if(temp->children == 1){
                random_child_func(node,x1,y1);
            }
        }
    }
}

/* This part of the code checks if there is only one child, in which case merging has to take place */

void qst::random_child_func(qnode* node, int x1, int y1)
{
    qinternalnode* temp = dynamic_cast<qinternalnode*>(node);
    string orientation = location(temp, x1, y1);
    
    if(temp->nw != NULL && temp->nw->internal == true && temp->ne == NULL && temp->sw == NULL && temp->se == NULL)
						  return;
    else if(temp->ne != NULL && temp->ne->internal == true && temp->nw == NULL && temp->sw == NULL && temp->se == NULL)
						  return;
    else if(temp->sw != NULL && temp->sw->internal == true && temp->nw == NULL && temp->ne == NULL && temp->se == NULL)
						  return;
    else if(temp->se != NULL && temp->se->internal == true && temp->nw == NULL && temp->ne == NULL && temp->sw == NULL)
						  return;
    else{
        int x;
        int y;
        string name;
        if(temp->nw != NULL && temp->nw->internal == false){
            name = temp->nw->cityName;
            x = temp->nw->x;
            y = temp->nw->y;
        }
        else if(temp->ne != NULL && temp->ne->internal == false){
            name = temp->ne->cityName;
            x = temp->ne->x;
            y = temp->ne->y;
        }
        else if(temp->sw != NULL && temp->sw->internal == true){
            name = temp->sw->cityName;
            x = temp->sw->x;
            y = temp->sw->y;
        }
        else if(temp->se != NULL && temp->se->internal == true){
            name = temp->se->cityName;
            x = temp->se->x;
            y = temp->se->y;
        }
        if(temp->parent == NULL){
            qleafnode* internal_node = new qleafnode(x, y, name, "se");
        }
        else{
            qinternalnode* temp2 = dynamic_cast<qinternalnode*>(temp->parent);
            if(temp2->nw == temp){
                temp2->nw = new qleafnode(x, y, name, "nw");
            }
            else if(temp2->ne == temp){
                temp2->ne = new qleafnode(x, y, name, "ne");
            }
            else if(temp2->sw == temp){
                temp2->sw = new qleafnode(x, y, name, "sw");
            }
            else if(temp2->se == temp){
                temp2->se = new qleafnode(x, y, name, "se");
            }
        }
    }
}


