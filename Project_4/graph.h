//
//  graph.h
//  DS_Program4
//
//  Created by Surabhi Ravishankar  on 12/2/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

#ifndef _GRAPH_H
#define _GRAPH_H
#include <iostream>
#include <string>
#include "locations.h"

using namespace std; 

/* 	This file basically deals with creating a graph based on locations. 
	Functions to define the graph structure are written here. Functions
	to add the vertices and edges are written in this file. 
*/
class graph
{
public:

	int number_roads;
	int graphSize;
	Loc_class *graphs;

	/* Default constructor */
	graph()
	{
		graphSize = 0;
		number_roads = 0;
		graphs = NULL;
	}

	/* Constructor that creates a new vertex */
	graph(int size)
	{
		graphSize = size;
		graphs = new Loc_class[graphSize];
	}

	/* destructor to delete all the vertices */
	~graph()
	{
		delete[] graphs;
	}
	
	/* 	Creates the nodes in the graph, That is it sets the names of all the destinations in the 
		Adjecency list 
	*/
	void addDestination(int dist, string name)
	{
		graphs[dist].setDestinationName(name);	
	}

	/* Adds vertices to the graph. That is, into the adjecency matrix */
	void addVertex(int start, int end, double distance, double speed, double time)
	{
		graphs[start].setList(end, distance, speed, time);
	}

	/* Gets the size of the adjecency list */
	int getMapSize()
	{
		return graphSize;
	}	
};
#endif
