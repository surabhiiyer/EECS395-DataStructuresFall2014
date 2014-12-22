//
//  dijkstra.cpp
//  DS_Program4
//
//  Created by Surabhi Ravishankar  on 12/2/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//
#include <string>
#include <vector>
#include <iostream>
#include "dijkstra.h"
#include "minHeap.h"

using namespace std;

/* This file implements the methods that are defined in dijkstra.h. */

/* Calculates the total distance form the start to end as specified by the inputs */
void dijkstra::calculate_distance(int begin, string type, int end)
{
	minHeap heap(30);
	heap.insert(begin, 0, 0, 0);
	
	int del_ind;
	float shortest_path;
	
	for (int i = 0; i < deleted_nodes.size(); i++)
	{
		deleted_nodes[i] = begin;
	}
	distance_vector[begin] = 0;

	while(heap.isEmpty() == false)
	{
		del_ind = heap.getMinimum().dest_index;
		heap.deleteMin();

		/* Maintains an array of visited nodes */
		visited[del_ind] = "Y";
		node* n;
		/* Take the node with the smallest cost */
		n = graph_ptr->graphs[del_ind].edges->first->next;

		/* Implementation of the shortest path calculation */
		while(n!=0)
		{
			shortest_path = distance_vector[del_ind] + n->getDistance();
			if ((visited[n->getDestination()] == "N") && (shortest_path < distance_vector[n->getDestination()]))
			{
				/* If the shortest path is found, then add it to the heap */
				distance_vector[n->getDestination()] = shortest_path;
				deleted_nodes[n->getDestination()] = del_ind;
				
				/* insert into the heap the node with the smallest distance */
				heap.insert(n->getDestination(), shortest_path, n->getSpeed(), n->getTime());
			}
			n = n->next;
		}
	}
	cout<<endl;
	}

	/* Extracting the order in which the vertices were visited */
	void dijkstra::get_order_distance(int begin, int end)
	{
	cout<<"Shortest distance from "<<graph_ptr->graphs[begin].getDestinationName()<<" to "<<graph_ptr->graphs[end].getDestinationName()<<":"<<endl;
	
	/* Maintains a vector that stores the order in which the nodes were visited */
	vector<int> order_of_traversal;
	
	int temp_node;
	int last_node = deleted_nodes[end];
	double total_dist;
	
	order_of_traversal.push_back(end);
	order_of_traversal.push_back(last_node);
	
	while(deleted_nodes[last_node] != begin)
	{
		order_of_traversal.push_back(deleted_nodes[last_node]);
		last_node = deleted_nodes[last_node];
	}
	
	order_of_traversal.push_back(begin);
	
	cout<<"Start at "<<graph_ptr->graphs[begin].getDestinationName()<<endl;

	/* For loop to extract and print the order in which the nodes were visited .. */
	for (int i = order_of_traversal.size() - 2; i >= 0; i--)
	{
		temp_node = order_of_traversal[i + 1];
		cout<<"Continue to: "<<graph_ptr->graphs[order_of_traversal[i]].getDestinationName()<<" ( "<<graph_ptr->graphs[temp_node].getList()->get_dist_list(order_of_traversal[i])<<" miles) "<<endl;
		/* Calculation of the total distance */
		total_dist = total_dist + graph_ptr->graphs[temp_node].getList()->get_dist_list(order_of_traversal[i]);
	}

	/* Prints the total distance in the standard output */
	cout<<"Total distance: "<<total_dist<<" miles"<<endl;
}
	
/* This functions implements the shortest driving time from a source to destination */
void dijkstra::calculate_time(int begin, int end)
{ 
	minHeap heap(30);
	int del_ind;
	float shortest_path;
	for (int i = 0; i < deleted_nodes.size(); i++)
	{
		deleted_nodes[i] = begin;
	}
	distance_vector[begin] = 0;
	heap.insert(begin, 0, 0, 0);

	/* Implementation of the dijkstra's algorithm */
	while(heap.isEmpty() == false)
	{
		del_ind = heap.getMinimum().dest_index;
		heap.deleteMin();
		visited[del_ind] = "Y";
		node* n;
		/* Extract the node with the minimum distance */
		n = graph_ptr->graphs[del_ind].edges->first->next;
		while(n!=0)
		{
			shortest_path = distance_vector[del_ind] + n->getTime();
			if ((visited[n->getDestination()] == "N") && (shortest_path < distance_vector[n->getDestination()]))
			{
				/* 	If the node is not visited before and it is shorter than the arrival time, then add the vertex 
					to the priority queue 
				*/
				distance_vector[n->getDestination()] = shortest_path;
				deleted_nodes[n->getDestination()] = del_ind;
				/* Adding the shortest path to the min heap */
				heap.insert(n->getDestination(), shortest_path, n->getSpeed(), n->getTime());
			}
			n = n->next;
		}
	}
	cout<<endl;
	}

	void dijkstra::get_order_time(int begin, int end)
	{
	cout<<"Shortest driving time from "<<graph_ptr->graphs[begin].getDestinationName()<<" to "<<graph_ptr->graphs[end].getDestinationName()<<"."<<endl;
	
	/* 	In order to find the shortest driving time, it is necessary to maintain a vector that stores the 
		order of traversal */
	vector<int> order_of_traversal;
	
	int last_node = deleted_nodes[end];
	
	double tot_time = 0.0;
	
	int temp_node;
	
	order_of_traversal.push_back(end);
	order_of_traversal.push_back(last_node);
	
	while(deleted_nodes[last_node] != begin)
	{
		order_of_traversal.push_back(deleted_nodes[last_node]);
		last_node = deleted_nodes[last_node];
	}
	
	order_of_traversal.push_back(begin);
	cout<<"Start at "<<graph_ptr->graphs[begin].getDestinationName()<<endl;
	
	/* for loop to extract and print the order in which the nodes are visited */
	for (int i = order_of_traversal.size() - 2; i >= 0; i--)
	{
		temp_node = order_of_traversal[i + 1];
		/* Extracting the time in hours from the graph */
		double hour = graph_ptr->graphs[temp_node].getList()->get_time_list(order_of_traversal[i]);
		int mins = graph_ptr->graphs[temp_node].getList()->get_time_list(order_of_traversal[i]) * 60;
		int secs = graph_ptr->graphs[temp_node].getList()->get_time_list(order_of_traversal[i]) * 3600 - mins * 60;
		
		/* Printing the next node in the shortest path */
		cout<<"Continue to: "<<graph_ptr->graphs[order_of_traversal[i]].getDestinationName()<<" ( "<<mins<<" mins "<<secs<<" secs) "<<endl;
		
		/* Adding the total time taken */
		tot_time = tot_time + hour;
	}

	/* Conversion as per specifications of the question */
	int time_mins = tot_time * 60;
	int time_secs = tot_time * 3600 - time_mins* 60;
	cout<<"Total time: "<<time_mins<<" mins "<<time_secs<<" secs"<<endl;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
