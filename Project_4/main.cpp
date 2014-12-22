//
//  main.cpp
//  DS_Program4
//
//  Created by Surabhi Ravishankar  on 12/2/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

#include <iostream>
#include <vector>
#include "main_functions.h" 

using namespace std; 

/* The execution of the dijkstras algorithm takes place in this file */
int main(int argc, char* argv[])
{

	/* Error if Insufficient command line arguements are given */
	if(argc < 2)
	{
		cout << "Insufficient Command line arguements please run the program as follows: "<<endl;
		cout << "./proj4 locations.txt segments.txt trips.txt"<<endl; 
	}

	else
	{
		cout << endl <<"****************************************************************** "<<endl;                       
		cout <<"CALCULATING SHORTEST DISTANCE AND TIME USING DIJKSTRAS ALGORITHM: "<<endl; 
		cout <<"****************************************************************** "<<endl;

		int loc_size = get_loc_size(argv[1]);
		std::vector<string> loc;

		/* First arguement is the locations file */
		loc = locations(argv[1]); 
		graph g(loc_size);

		/* Creating the vertices for the graph */
	    for (int i = 0; i < loc.size(); i++)
	    {
	    	g.addDestination(i, loc[i]);
	    }
	 	
	 	/* Creating the graph by adding edges */
	 	segment(&g, argv[2]);
	 	
	 	/* 	Calculation of the shortest path based on dijkstra's algorithm (calculates the shortest distance and time 
	 		based on the input files)*/
	 	trips(&g, argv[3]);
 }
}
