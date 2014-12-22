//
//  bst.cpp
//  DS_Proj2_v4
//
//  Created by Surabhi Ravishankar  on 11/9/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

#include "bst.h"
#include <iostream>

using namespace std;


bst::bst(){
	root = NULL;
}

void bst::makenull(){
	bst();
}

void bst::destroy(bnode* node){
	if(node!=NULL)
	{
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

/* The Binary Search Tree insert function was implemented by the following algorithm:
 
 Insert function is recursive.
 
 insert(int data)
     return insert( data, root );
 
 insert(int data, Node *&node)
     if( node == NULL )
         node = new Node(data);
     else
        if( data > node->getData() )
             return insert( data, node->getRight() );
        else
             return insert( data, node->getLeft() );

*/

void bst::insert(bnode* node, int x1, int y1, string name){
    
        if (node == NULL){
		node = new bnode(x1, y1, name);
		if(root == NULL)
			root=node;
		return;
	}
	else if (name < node->cityName){
		if (node->left!= NULL){
			insert(node->left, x1, y1, name);
		}
		else{
			bnode* newNode = new bnode(x1, y1, name);
			node->left = newNode;
		}
	}

	else if (name > node->cityName){
		if (node->right!= NULL){
			insert(node->right, x1, y1, name);
		}
		else{
			bnode* newNode = new bnode(x1, y1, name);
			node->right = newNode;
		}
	}

	else if (name == node->cityName){
		while (node->down!= NULL){
			node = node->down;
		}
		bnode* newNode = new bnode(x1, y1, name);
		node->down = newNode;
	}

}



/*  Remove Function is implemented similar to the insert function in a recursive manner.
    Algorithm:
 
    remove(city, node)
    {
    checks for 3 cases.
     1. left child
        city > node -> cityName --- remove from left subtree
     2. Right Child
        city < node -> cityName --- remove from right subtree
     3. Node with 2 children.
        city = node -> cityName --- add below


    }
*/

void bst::remove(string name, bnode* &node){
	if (node == NULL){
		cout<<"CANT FIND NODE"<<endl;
		return;
	}
		
	if (name < node->cityName){
		remove(name, node->left);
	}
	else if (name > node->cityName){
		remove(name, node->right);
	}
	else if (node->left != NULL && node->right != NULL){
		cout<<"2 CHILDREN"<<endl;
		node-> cityName = (min(node->right)->cityName);
		node-> x = (min(node->right)->x);
		node->y = (min(node->right)->y);
		node->down = (min(node->right)->down);
		remove(node->cityName, node->right);
	}
	else{
		bnode* current =  node;
		if (node->left != NULL){
			node = node->left;
		}
		else{
			node = node->right;
		}
		delete current;
	}
}

/* This function returns the minimum element */

bnode* bst::min(bnode* node){
	if(node == NULL)
        return NULL;
	if(node->left == NULL)
        return node;
	return min(node->left);
}

/* This function implements PreOrder Traversal */

/* Algorithm:
    Visit root,
    Visit Left Child 
    Visit Right Child 
 */

void bst::traverse(bnode* node){
	if(node == NULL){
		return;  
	}
	visit(node);
	traverse(node->left); 
	traverse(node->right); 
}

/* PreOrder Traversal */

void bst::visit(bnode* node){
	if (node->down!=NULL){
		while (node->down!= NULL){
			cout<<"CITY: "<<node->cityName<<"  X: "<<node->x<<"  Y:"<<node->y<<endl;
			node = node->down;
		}
		cout<<"CITY: "<<node->cityName<<"  X: "<<node->x<<"  Y:"<<node->y<<endl;
	}
	else{
		cout<<"CITY: "<<node->cityName<<"  X: "<<node->x<<"  Y:"<<node->y<<endl;
	}
}

/* Implements the Search function for the Binary Search Tree */

bnode* bst::find(string name, bnode* node){
	if (node == NULL)
	{
		cout<<"CAN'T FIND NODE "<<endl;
		return NULL;
	}
	else if((name == node->cityName)) 
    {
		visit(node);
		return node;
    }
    
	else if(name < node->cityName)
	{
		return find(name, node->left);
    }
    else
    {
		return find(name, node->right);
    }
}
