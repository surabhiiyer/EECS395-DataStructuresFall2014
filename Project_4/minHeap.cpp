//
//  minHeap.cpp
//  DS_Program4
//
//  Created by Surabhi Ravishankar  on 12/2/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//
#include <iostream>
#include "minHeap.h"

using namespace std; 

/* Check if the heap is empty */
bool minHeap::isEmpty()
{
    return (heap_size == 0);
}

/* The element at the 0 index is the min. Return that */
node minHeap::getMinimum()
{
	if (isEmpty())
    	throw string("Empty");
    else
        return data[0];
}

/* Insert into the heap */
void minHeap::insert(int end, double distance, double speed, double time)
{
	if (heap_size == array_size)
    	throw string("Overflow");
    else
    {
		heap_size++;
		data[heap_size - 1].dest_index = end;
		data[heap_size - 1].dist = distance;
		data[heap_size - 1].speed = speed;
		data[heap_size - 1].time = time;
        shiftUp(heap_size - 1);
    }
}

/* Make the shortest distance the parent */
void minHeap::shiftUp(int node_index)
{
	int parent_index;
	node temp_node;
    if (node_index != 0) 
    {
    	parent_index = getParentIndex(node_index);
        if (data[parent_index].dist > data[node_index].dist)
        {
        	temp_node = data[parent_index];
            data[parent_index] = data[node_index];
            data[node_index] = temp_node;
            shiftUp(parent_index);
        }
    }
}

/* Delete the node at index 0 because that is the min dist */
void minHeap::deleteMin()
{
	if (isEmpty())
    	throw string("Empty");
    else 
    {
    	data[0] = data[heap_size - 1];
        heap_size--;
      	if (heap_size > 0)
        	shiftDown(0);
    }
}

/* Array implementation of the min heap. Return the left and the right child accordingly */
/* Left child 2(node) + 1 */
int minHeap::getLeftChildIndex(int node_index)
{
    return 2 * node_index + 1;
}

/* Right child 2(node) + 1 */
int minHeap::getRightChildIndex(int node_index)
{
    return 2 * node_index + 2;
}

/* Index of the parent is node - 1/2  */
int minHeap::getParentIndex(int node_index)
{
    return (node_index - 1) / 2;
}

/* If the value at the parent index is greater that the childen nodes, then move the parent down */
void minHeap::shiftDown(int node_index)
{
	int left_index, right_index, min_index;
	node temp_node;

    left_index = getLeftChildIndex(node_index);
    right_index = getRightChildIndex(node_index);
    
    /* Make left index smaller if right is greater than the heap size */
    if (right_index >= heap_size) 
    {
    	if (left_index >= heap_size)
        	return;
        else
            min_index = left_index;
    } 

    /* Make right index smaller if right is greater than the heap size */
    else 
    {
        if (data[left_index].dist <= data[right_index].dist)
        	min_index = left_index;
        else
            min_index = right_index;
    }

    /* Swap operation to switch the left and the right children depending on the min dist*/
    if (data[node_index].dist > data[min_index].dist) 
    {
        temp_node = data[min_index];
        data[min_index] = data[node_index];
        data[node_index] = temp_node;
        shiftDown(min_index);
    }

}

	

	
