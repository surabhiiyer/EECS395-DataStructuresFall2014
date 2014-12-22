//
//  AdjList.h
//  DS_Program4
//
//  Created by Surabhi Ravishankar  on 12/2/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//
#ifndef _ADJLIST_H
#define _ADJLIST_H
#include "node.h"

/* This class is used to create the adjecency list based on the nodes */
class list
{	
public:
	node* first;
	int list_size;

	/* Constructor */
	list()
	{
		first = new node();
		list_size = 0;
		first->next = NULL;
	}

	/* Destructor */
	~list()
	{	
		node* current;
		while(first)
		{
			current = first->next;
			delete first;
			first = current;
		}
	}
	
	/* Creating the adjecency list */
	void insert_at_front(int e, double d, double s, double t)
	{
		node* vertex = new node(e, d, s, t);
		vertex->next = first->next;
		first->next = vertex;
		list_size++;
	}

	/* Print function to print out the adjecency matrix */
	void print()
	{
		node* current = first->next;
		while(current)
		{
			cout<<current->getDestination()<<"  "<<current->getDistance()<<"  "<<current->getSpeed()<<"   "<<current->getTime()<<endl;
			current = current->next;
		}
		cout<<endl;
	}

	/* Returns the size of the adjeceny list */
	int getListSize()
	{
		return list_size;
	}

	/* Returns the distance at every step */
	double get_dist_list(int end)
	{
		node* current = first->next;
		while(current)
		{
			if (end == current->getDestination())
			{
				return current->getDistance();
				//break; 
			}
			current = current->next;
		}
		return 0.0; 
	}

	/* Returns the time from the adjecency list */
	double get_time_list(int end)
	{
		node* current = first->next;
		while(current)
		{
			if (end == current->getDestination())
			{
				return current->getTime();
				//break; 
			}
			current = current->next;
		}
		return 0.0; 
	}
};
#endif
