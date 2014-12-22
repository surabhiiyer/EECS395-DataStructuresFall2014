//
//  main.cpp
//  newfinal
//
//  Created by Aakash Anand Mishra on 10/24/14.
//  Copyright (c) 2014 Aakash Anand Mishra. All rights reserved.
//

#include <stdio.h>
#include <cctype>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "func.h"

using namespace std;

int main (int argc, char* argv[])
{
	    
//command line arguements 
    string filename;
    filename = argv[1];
    int startx = atoi(argv[2]);
    int starty = atoi(argv[3]);
    int endx = atoi(argv[4]);
    int endy = atoi(argv[5]);
    
    read_file(filename,startx,starty,endx,endy);
    create_neighbours(startx, starty, endx,endy);
    find_distance(startx, starty, endx,endy);
}


