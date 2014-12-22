//
//  functions.h
//  DS_Proj2_v4
//
//  Created by Surabhi Ravishankar  on 11/9/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//
#include "qst.h" 
#include "bst.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

qst qtree;
bst btree;

void prcss(vector<string>);

void prcss(vector<string> inptvctr){
	string cmmnd = inptvctr[0];
        
	string name;
	int x,y,r;
	bool z;
	bnode* node;
    
	/*  "Insert" --- into the BST and the Quad Tree
        "makenull" --- Creating the BST and the PR Quad Tree
        "find" --- name search in the Binary Search Tree
        "search" --- traverses through the PR Quad Tree and returns the required results 
        "remove" --- The function first removes from the Binary Search Tree and then the coordinates are removed 
                     from the PR Quad Tree"
        
        The above functions were implemented using vectors by storing the command line arguements in vectors.
     
     */
		 if(cmmnd=="insert"){
				x = atoi(inptvctr[1].c_str());
				y = atoi(inptvctr[2].c_str());		
				name = inptvctr[3]; 
				z = qtree.insert(x, y, name);
				if (z == true)
					btree.insert(btree.root,x, y, name);		
    			}
		  if(cmmnd=="makenull"){
				qtree.makenull();
				btree.makenull();
				}
		  if(cmmnd=="find"){
				name = inptvctr[1];
				node = btree.find(name,btree.root);
				}
		  if(cmmnd=="debug"){
				qtree.debug(qtree.internal_node);
				}
		  if(cmmnd=="search"){
				x = atoi(inptvctr[1].c_str());
				y = atoi(inptvctr[2].c_str());
				r = atoi(inptvctr[3].c_str());
				qtree.search(qtree.internal_node,x, y, r);
				}
		  if(cmmnd=="remove"){

				if (inptvctr.size() == 2){

					name = inptvctr[1];
					node = btree.find(name,btree.root);
					if (node == NULL){
						cout<<"NODE DOES NOT EXIST "<<endl;
					}
					else{
						
                        if (node->down == NULL){}
						
                        else{
							while(node->down!=NULL){
                                cout<<"REMOVING IN PR QUAD TREE "<< endl;
                                cout<<"CITY REMOVED: "<<node->cityName<<" X: "<<node->x<<" Y: "<<node->y<<endl;
                                qtree.remove(qtree.internal_node,node->x, node->y);
								node = node->down;
							}
                            cout<<"REMOVING IN BINARY SEARCH TREE "<<endl;
							cout<<"CITY REMOVED: "<<name<<endl;
							btree.remove(name,btree.root);
						}
					}
				}
				else{
					qnode* nodeq = NULL;
					x = atoi(inptvctr[1].c_str());
					y = atoi(inptvctr[2].c_str());
					nodeq = qtree.find(x, y);
					if (nodeq == NULL){
						cout<<"NODE DOES NOT EXIST "<<endl;
					}
					else{
                        cout<<"REMOVING IN PR QUAD TREE "<< endl;
                        cout<<nodeq->cityName<<" X: "<<nodeq->x<<" Y: "<<nodeq->y<<endl;
						qtree.remove(qtree.internal_node,x, y);
                        cout<<"REMOVING IN BINARY SEARCH TREE "<<endl;
                        cout<<nodeq->cityName<<endl;
						btree.remove(nodeq->cityName,btree.root);
					}
				}
				}
	
}
