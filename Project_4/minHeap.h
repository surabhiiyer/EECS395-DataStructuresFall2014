//
//  minHeap.h
//  DS_Program4
//
//  Created by Surabhi Ravishankar  on 12/2/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//
#ifndef _MINHEAP_H
#define _MINHEAP_H
#include <iostream>
#include <string>
#include "node.h"

using namespace std;

/* 	The min heap is used to store all the nodes. This is a priority queue implementation.
	Everytime a non visited node is encounterd and it is along the shortest path, the node
	is added to the minHeap. Then popped and the algorithm is performed again. 
*/

class minHeap
{
public:

	
	node* data;
	int array_size;
	int heap_size;
	
	/* Constructor */
	minHeap(int size)
	{
		data = new node[size];
    	heap_size = 0;
    	array_size = size;
	}

	/* Destuctor */
	~minHeap()
	{
		delete[] data;
	}
	
	/* Checks if the heap is empty */
	bool isEmpty();

	/* Deletes the min element, that is the min node in the Priority Queue */
	void deleteMin();

	/* Move the node down in the tree*/
	void shiftDown(int nodeIndex);

	/* Insert into the Heap when min distance is found */
	void insert(int end, double distance, double speed, double time);

	/* Move the node up the tree */
	void shiftUp(int nodeIndex);

	/* Return the smallest node in the tree */
	node getMinimum();

	/* Left child of the tree */
	int getLeftChildIndex(int nodeIndex);

	/* Right Child of the tree */
	int getRightChildIndex(int nodeIndex);

	/* Index of the parent of the node */
	int getParentIndex(int nodeIndex);


};
#endif 
