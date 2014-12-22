//
//  node.h
//  DS_Program4
//
//  Created by Surabhi Ravishankar  on 12/2/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

#ifndef _NODE_H
#define _NODE_H
#include <iostream> 

using namespace std; 

/* 	This file contains the node class. It stores information of each of the ndoes. 
	I have created a property graph where in each node contains the following 
	information, distance, speed and time. These nodes are later used in the graph 
	class which is used to create the graph according to the input files 
*/

class node
{
public:

	/* Variables for speed, distance and time */
	int dest_index;
	double speed;
	double dist;
	double time;
	
	/* Next pointer, to point to the next node in the graph */
	node *next;
	
	/* Default constructor */
	node()
	{
		dest_index = 0;
		dist = 0;
		speed = 0;
		time = 0;
		next = NULL;
	}

	/* Initializing values for each of the nodes for the structure */
	node(int end, double distance, double s, double t)
	{
		dest_index = end;
		dist = distance;
		speed = s;
		time = t;
		next = NULL;
	}

	/* Destructor */
	~node()
	{
	
	}	

	/* 	The following funtions are self explantory. 
		setDestination = returns the index of the destination vertex. 
		setDistance = sets the distance of the nodes 
		setSpeed = sets the speed according to the input files 
		setTime = sets the time taken. 	

		Similarly, all the get methods do the same things, the return the distance, speed and time respectively 
	*/
	void setDestination(int end)
	{
		dest_index = end;
	}

	void setDistance(double distance)
	{
		dist = distance;
	}

	void setSpeed(double s)
	{
		speed = s;
	}

	void setTime(double t)
	{
		time = t;
	}

	int getDestination()
	{
		return dest_index;
	}	

	double getDistance()
	{
		return dist;
	}

	double getSpeed()
	{
		return speed;
	}

	double getTime()
	{
		return time;
	}
};
#endif
