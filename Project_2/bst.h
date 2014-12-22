//  bst.h
//  DS_Proj2_v4
//
//  Created by Surabhi Ravishankar  on 11/9/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.


#include <string>
#include <iostream>

using namespace std;

class bnode{
public:
	int x;
	int y;
    string cityName ;
    	bnode *left;
    	bnode *right;
	bnode *down;
	
    bnode(){
		left = NULL; 
		right = NULL; 
		down = NULL; 
		x = 0;
		y = 0;
		cityName = "";
	}
	
    bnode(int x1, int y1, string name){
		x = x1;
		y = y1;
		cityName = name;
		left = NULL; 
		right = NULL; 
		down = NULL; 
	}
};


class bst{

public:
	bnode *root;
	bst();
	bst(int x1, int y1, string name);
    void traverse(bnode* node);
    void visit(bnode* node);
    void makenull();
    void destroy(bnode* node);
	void insert(bnode* node, int x1, int y1, string name);
	void remove(string name,bnode* &node);
	bnode* find(string name, bnode* node);
	bnode* min(bnode* node);

};
