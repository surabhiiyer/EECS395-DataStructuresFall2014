//
//  main_functions.h
//  DS_Program4
//
//  Created by Surabhi Ravishankar  on 12/2/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//


#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <fstream>
#
#include "graph.h"
#include "dijkstra.h"

using namespace std;

string line = "";
string str = "";
int loc_size = 0;

/* Start location */
int start_point;

/* End location */
int end_point;

/* This function is used to extract the location name and return a string */
string get_loc_name(vector<string> location);

/* 	This function is defined to extract the Number of locations from the file 
	and return the size 
*/	
int get_loc_size(string filename);

/* 	This function is defined to extract the location details from the user, creates 
	a vector and spits out the values 
*/
vector<string> locations(string filename);

/* 	This function is defined to extract the segment details from the file and adds vertices to the
	graph. 
*/
void segment(graph *g, string filename);

/* 	This function is defined to extract the trip details from the file, 
	Then calls the dijkstra's shortest path algorithm to calculate the 
	shortest path. Calculates the shortest time if the input is T 
	and the shortest distance if the input is T. 
*/
void trips(graph *g, string filename);

string get_loc_name(vector<string> location)
{
	string name;
	for (int i = 0; i < location.size() - 1; i++)
	{
		name = name + location[i] + " ";
	}
	name = name + location[location.size() - 1];
	return name;
}	

int get_loc_size(string filename) 
{ 
  	ifstream loc_file; 
	loc_file.open(filename.c_str());
	vector<string> locations;
	while (getline(loc_file, line))
    {
    	vector <string> loc;
		istringstream stream(line);    
		while(stream>>str)   
		{  
			loc.push_back(str);
		}
		/* extracts the location size as specified in the file */
		if (loc.size() == 1)
		{
			loc_size = atoi(loc[0].c_str());
		}
		if (loc.size() == 0 || loc[0] == "#" || loc.size() == 1)
		{
			continue;
		}
    }
    
    loc_file.close();
    return loc_size;
}

/* Returns a vector containing all the locations in order to store the locations */
vector<string> locations(string filename)
{
	ifstream loc_file; 
	loc_file.open(filename.c_str());
	vector<string> locations_vector;
	while (getline(loc_file, line))
    {
    	vector <string> loc;
		istringstream stream(line);    
		while(stream>>str)   
		{  
			loc.push_back(str);
		}
		if (loc.size() == 1)
		{
			loc_size = atoi(loc[0].c_str());
		}
		if (loc.size() == 0 || loc[0] == "#" || loc.size() == 1)
		{
			continue;
		}
		/* Adding locations to the vecotor and returns the locations as a vector */
		else
		{
			locations_vector.push_back(get_loc_name(loc));
		}
    }
     loc_file.close();
     return locations_vector; 
}

/* Reads the input from the file and adds the edges to the graph */
void segment(graph *g,string filename)
{
 	
    ifstream seg_file;
    int segmentsSize;

    double segment_no;
	seg_file.open(filename.c_str());
    while (getline(seg_file, line))
    {
    	vector<double> segments;
    	vector <string> segs;
		istringstream stream(line);    
		while(stream>>str)   
		{  
			segs.push_back(str);
		}
		if (segs.size() == 1)
		{
			segmentsSize = atoi(segs[0].c_str());
		}
		if (segs.size() == 0 || segs[0] == "#" || segs.size() == 1)
		{
			continue;
		}
		for (int i = 0; i < segs.size(); i++)
		{
			segment_no = atof(segs[i].c_str());
			segments.push_back(segment_no);
		}

		/* calculating time */
		double times = segments[2]/segments[3];

		/* Adding edges to the graph */
		g->addVertex(segments[0], segments[1], segments[2], segments[3], (segments[2] / segments[3]));
    }
    seg_file.close();
}

/* Reads the input from the files and calculates the shortest path and shortest distance */
void trips(graph *g, string filename)
{
	ifstream t_file;
    t_file.open(filename.c_str());
    while (getline(t_file, line))
    {
    	istringstream stream(line);   
    	vector <string> input; 
		while(stream>>str)   
		{  
			input.push_back(str);
		}
		if (input.size() == 0 || input[0] == "#" || input.size() == 1)
		{
			continue;
		}
		start_point = atoi(input[0].c_str());
		end_point = atoi(input[1].c_str());
		
		/* If the input is D calculte the shortest distance */
		/* Print the order of traversal as well */
		if (input[2] == "D")
		{
			dijkstra d(g, loc_size);
			d.calculate_distance(start_point, "T", end_point);
			d.get_order_distance(start_point, end_point);
		}
		
		/* If the input is T calculate the shortest time */
		/* Print the order of traversal as well */
		if (input[2] == "T")
		{
			dijkstra d(g, loc_size);
			d.calculate_time(start_point, end_point);
			d.get_order_time(start_point, end_point); 
		}
		cout<<endl;
	}
	t_file.close();
}
