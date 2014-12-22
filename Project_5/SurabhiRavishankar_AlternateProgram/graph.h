//
//  graph.h
//  wordladder
//
//  Created by Surabhi Ravishankar  on 12/7/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <ctime>
using namespace std;

class graph
{
public:
	struct node
	{	
		string data; 
		node *next; 
		int edge_number; 
		bool visited; 
	}; 

	/* reading the input file */
	vector<string> read_input(string filename);

	/*get length of each word in the wordlist */
	int calc_len(string filename);

	/* Function to compare characters */
	bool compare_characters(string word1, string word2);
	/* Creating a graph */
	map<string,vector<string> > create_graph(vector<string> wordlist); 
	/* BFS */
	vector<string> get_path_BFS(const map<string,vector<string> > & adj_list, const string & first, const string & second);
	vector<string> get_path_BFS(const vector<string> & adj_list,const string & first,const string & second);
	vector<string> reverse_path(const map<string,string> & adj_list, const string & first, const string & second);

};

