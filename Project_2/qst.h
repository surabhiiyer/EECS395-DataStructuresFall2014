
//
//  qst.h
//  DS_Proj2_v4
//
//  Created by Surabhi Ravishankar  on 11/9/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

#include <string>
#include <iostream>

using namespace std;

/* This file implements the PR Quad Tree. All the class declarations are contained here. 
   I have used Inheritance in order to implement the PR Quad Trees. This consists of a 
   base calss "qnode" which have sub classes for internal nodes and external leaf nodes,
   qleafnode and qinternal node.
*/

// Base class
class qnode{
public:
	int x_min, x_max, y_min, y_max, x, y;
	string cityName;
	string pdirection;
	qnode* nw;
	qnode* ne;
	qnode* sw;
	qnode* se;
	qnode* parent;
	bool internal;
	int children;

	virtual ~qnode()
	{

	}
};

// qleafnode inherits from the qnode base calss.
class qleafnode : public qnode{
public:
    
    /* Stores the directions
        1. Northeast
        2. Northwest 
        3. Southeast 
        4. Southwest
     
      Stores values for x and y coordinates 
      Store the Direction in the parent node -> pdirection.
        
      Holds number of children. 
     
     */
    
	qleafnode(string dir){
		nw = NULL;
		ne = NULL;
		sw = NULL;
		se = NULL;
		x = 0;
		y = 0;
		cityName = "";
		pdirection = dir;
		internal = false;
		children = 0;
		parent = NULL;
	}
    
    // Constructor
	qleafnode(int x1, int y1, string name, string dir){
		nw = NULL;
		ne = NULL;
		sw = NULL;
		se = NULL;
		x = x1;
		y = y1;
		cityName = name;
		pdirection = dir;
		internal = false;
		children = 0;
		parent = NULL;
	}
};

// qinternalnode inherits from the qnode base calss.
class qinternalnode : public qnode{
public:
	qinternalnode(int x_Min, int x_Max, int y_Min, int y_Max){
		x_min = x_Min;
		x_max = x_Max;
		y_min = y_Min;
		y_max = y_Max;
		nw = NULL;
		ne = NULL;
		sw = NULL;
		se = NULL;
		internal = true;
		children = 0;
		parent = NULL;
	}
};

// A class that implments all the functions that has to be implemented by the PR Quad Tree.
class qst{
public:
	qinternalnode* internal_node;
    
    qleafnode* leafRoot;
	
    qst();
	
    void makenull();                                                // Initializing the Tree
	
    bool isEmpty();
    
    void visitNode(qnode* Node);                                    // PreOrder Traversal

    void search(qnode* node, int x1, int y1, int radius);           // Search Function that uses radius to determine which cities that lie within a particular radius.
    
    void debug(qnode* node);                                        // PreOrder Listing of the Tree
    
    bool insert(int x1, int y1, string name);                       // Insert into the PR Quad Tree
	
    void remove(qnode* root, int x1, int y1);                       // Remove from the PR Quad Tree
	
    qnode* find(int x1, int y1);                                    // Find function that uses the coordinates as parameters.
	
    void random_child_func(qnode* node, int x1, int y1);            // Used for Removal
	
    void radius_func(qnode* node, int x1, int y1, int radius);      // Used for Removal

private:
    
    string location(qinternalnode* node, int x1, int y1);
    
    qnode* findNode(qnode* node, int x1, int y1);

    void random_func(qnode* temp,qnode* node,qnode* nodedir, int x1, int y1);
    
    qnode* find(qnode* node, int x1, int y1);
   
    bool insert(qnode* node, int x1, int y_coordiante, string name);

};
