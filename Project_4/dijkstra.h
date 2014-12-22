//
//  dijkstra.h
//  DS_Program4
//
//  Created by Surabhi Ravishankar  on 12/2/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//
#include <vector>
#include <iostream>
#include <string> 
#include "graph.h"
#include "minHeap.h"

using namespace std; 

/* 	This file contains the dijkstra's class that has to be implemented */
/* 	It contains all the definitions to initialize all the nodes in the 
	graph as visited and initialize the distances to each of the nodes 
	as infinity. I have used 9999 to initialize all the distance 
	(assuming that it is the max) 
*/

class dijkstra
{
public:
	/* Vector storing the visited nodes */
	vector<string> visited;
	/* Vector storing the distances to each of the vertices from source to destination */
	vector<double> distance_vector;
	
	vector<int> deleted_nodes;
	
	/* pointer to the graph structure */
	graph *graph_ptr;

	/* Constructor */
	dijkstra(graph *g, int size)
	{
		this->graph_ptr=g;
		visited.resize(size);
		distance_vector.resize(size);
		deleted_nodes.resize(size);
		
		/* According to the dijkstra's algorithm it is necessay to mark all the nodes as not visited initially */
		for (int i = 0; i < visited.size(); i++)
		{
			visited[i] = "N";
		}

		/* Initializing all the distances as infinity accodring to the dijkstra's algorithm */
		for (int i = 0; i < distance_vector.size(); i++)
		{
			distance_vector[i] = 9999;
		}
	}

	/* Destructor */
	~dijkstra()
	{

	}

	/* This function is defined to calculate the shortest path */
	void calculate_distance(int begin, string type, int end);
	/* This function extracts the order in which the nodes are visited */
	void get_order_distance(int begin, int end);
	
	/* Calculates the shortest time taken to visit all the nodes */
	void calculate_time(int begin, int end);
	/* This function extracts the order in which the nodes are traversed and prints the output */
	void get_order_time(int begin, int end);
	
};