//
//  locations.h
//  DS_Program4
//
//  Created by Surabhi Ravishankar  on 12/2/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//
#include<iostream>
#include<string>
#include "AdjList.h"	

/* Used to create the adjecency list */
using namespace std;

class Loc_class
{
public:
	list *edges;

	string destination_name;
	
	/* Default Constructor */
	Loc_class()
	{
		edges = new list();
		destination_name = "";
	}

	/* Destructor to avoid memory leaks */
	~Loc_class()
	{
		delete edges;
	}

	void setDestinationName(string name)
	{
		destination_name = name;
	}

	/* This function deals with inserting the information about the vertices into the adjecency list*/
	void setList(int end, double distance, double speed, double time)
	{
		edges->insert_at_front(end, distance, speed, time);
	}

	/* Returns the destination name */
	string getDestinationName()
	{
		return destination_name;
	}

	/* Returns the edges from the adjecency List*/  
	list* getList()
	{
		return edges;
	}
	
};