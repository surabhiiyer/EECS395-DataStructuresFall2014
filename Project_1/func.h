//
//  func.h
//  DS_Proj1_Final
//
//  Created by Surabhi Ravishankar  on 10/26/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

#include<iostream>
#include <cctype>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <algorithm>
#include "queue.h"

//int startx = 0;
//int starty = 0;

int array_row[100];
int array_col[100];

int endx = 0;
int endy = 0;

int ai = 0;
int row = 0;        //total number of rows

int total_r = 0;
int total_colums = 0;

int grid[100][100];

int dist = 0;

int r = 0;
int c_t = 0;
int c;
int outlength;
int count1 = -1;

Path temp;
Path coord;
Path temp1;
Path check;
Path start;
Path last_elem;
Queue<Path> p;
Queue<Path> p1;
Queue<Path> path_coord;
void print_coordinates();

//Function to read the sample input file 
void read_file(std::string filename, int startx, int starty, int endx, int endy)
{
    
    std::ifstream input_file(filename.c_str(), std::ifstream::in);
    
    if(input_file.fail())
    {
        std::cout<<"Error Reading File "<<std::endl;
    }
    
    else
    {
    char c = input_file.get();
    
    while (!input_file.eof()){
        if(c=='1'){
            grid[row][c_t] = 1;
            c_t++;
        }
        else if(c=='0'){
            grid[row][c_t] = 0;
            c_t++;
        }
        else if (c=='S'){
            startx = row;
            starty = c_t;
            grid[row][c_t] = 10; //start element is set to 10
            c_t++;
        }
        else if (c=='T'){
            endx = row;
            endy = c_t;
            grid[row][c_t] = 1;
            c_t++;
            
        }
        else if (c=='\n'){
            row = row + 1;
            total_colums = c_t ;
            c_t =0;
            
        }
        c = input_file.get();
    }
    }
}


//function to calculate the total number of rows
int total_rows(std::string filename)
{
    int rows;
    int cols;
    char c;
    std::string line;
    std::ifstream input_file;
    input_file.open(filename.c_str(), std::ios::in);
    
    getline(input_file,line);
    line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
    std::cout << "new line = "<<line<<std::endl;
    cols = int(line.length());
    
    while(!input_file.eof() ) {
        input_file.get(c);
        if(c == '\n')
        {
            rows++;
        }
    }
    
    input_file.close();
    
    std::cout << "Number of rows = "<<rows<<std::endl;
    return rows;
}
//Function to calculate total number of columns
int total_cols(std::string filename)
{
    int cols;
    
    std::string line;
    
    std::ifstream input_file;
    input_file.open("sample_grid", std::ios::in);
    
    getline(input_file,line);
    line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
    cols = int(line.length());
    input_file.close();
    std::cout << "Number of cols = "<<cols<<std::endl;
    return cols;
}
//Function to calculate the neighbours 
void create_neighbours(int startx, int starty, int endx, int endy)
{
    
    start.row= startx;
    start.col= starty;
    p.push(start); //push the first element onto the queue 
    
    
    while(!p.IsEmpty())
    {
        temp = p.pop();
        if(temp.row == endx and temp.col == endy)
        {
            p.pop();
            break;
        }
        
        r = temp.row;
        c = temp.col;
        
        int counter = grid[r][c];

        //right
            if((grid[r][c+1] == 1)and c<total_colums) {
                grid[r][c+1] = 1 + counter;
                temp.row = r;
                temp.col = c + 1;
                p.push(temp);
            }
	//left
            if((grid[r][c-1] == 1) and c>0){
                grid[r][c-1] = 1 + counter;
                temp.row = r;
                temp.col = c -1;
                p.push(temp);
            }
	//top 
            if((grid[r+1][c] == 1) and r<row){
                grid[r+1][c] = 1 + counter;
                temp.row = r + 1;
                temp.col = c;
                p.push(temp);
            }
	//bottom
            if((grid[r-1][c] == 1)and r>0){
                grid[r-1][c] = 1 + counter;
                temp.row = r -1;
                temp.col = c;
                p.push(temp);
            }
            
        //}
    }
    
    std::cout<<"Printing the grid with neighbour values "<<std::endl;
    
    for (int i =0;i<row; i++)
    {
        for(int j=0;j<total_colums;j++){
            std::cout << grid[i][j]<<"\t";
        }
        std::cout <<std::endl;
    }
}

//this function finds the distance from last element to the first and prints the coordinates
void find_distance(int startx, int starty, int endx, int endy)
{
    
    if(grid[endx][endy]!=1)
    {
        int tr;
        int tc;
        last_elem.row = endx;
        last_elem.col = endy;
        
        startx = start.row;
        starty = start.col;
        
        p1.push(last_elem);
        path_coord.push(last_elem);

        while (!p1.IsEmpty()) {
            
            temp = p1.pop();
            tr = temp.row;
            tc = temp.col;
            
            
            int max_val = grid[tr][tc];

            //left
            if((grid[tr][tc-1] == (max_val - 1)) && tc>0)
            {
                temp1.row = tr;
                temp1.col = tc-1;
                path_coord.push(temp1);
                p1.push(temp1);
            }
	//right
            else if(grid[tr][tc+1] == (max_val - 1) && tc<total_colums)
            {
                temp1.row = tr;
                temp1.col = tc+1;
                p1.push(temp1);
                path_coord.push(temp1);
            }

	//bottom
            else if(grid[tr-1][tc] == (max_val - 1) && tr>0)
            {
                temp1.row = tr-1;
                temp1.col = tc;
                path_coord.push(temp1);
                p1.push(temp1);
            }
	//top
            else if((grid[tr+1][tc] == (max_val-1) ) && tr<row){
                
                temp1.row = tr+1;
                temp1.col = tc;
                path_coord.push(temp1);
                p1.push(temp1);
            }
            
        }
        
    }
    
    while(!path_coord.IsEmpty())
    {
        coord = path_coord.pop();
        array_row[ai] = coord.row;
        array_col[ai] = coord.col;
        ai++;
    }

    if(grid[endx][endy]== 1)
    {
        dist = 0;
    }
    else
    {
        dist = grid[endx][endy] - 10;
    }
    std::cout<<"The distance from the begining to end  = "<< dist <<std::endl;
    
    std::cout<<"The shortest path is: "<< std::endl;
    
    for(int a=ai;a>0;a--)
    {
        std::cout <<"("<< array_row[a]<<","<<array_col[a]<<")"<<std::endl;
    }
}


















