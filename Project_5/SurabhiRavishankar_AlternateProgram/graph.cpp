//
//  graph.cpp
//  wordladder
//
//  Created by Surabhi Ravishankar  on 12/7/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <algorithm> 
#include "graph.h"
#include "queue.h"

using namespace std;

/*  This function is used to compare two words and check if they are different 
    only by one character. This returns either true or false. 
*/
bool graph::compare_characters(string word1, string word2)
{
	
	int word1_len = word1.length(); 
	int word2_len = word1.length(); 

    /* Maintains a counter that increments everytime the words differ by a letter */
	int count = 0; 
	if (word1_len != word2_len)
	{
		return false; 
	}
	for(int i=0; i<word1_len; i++)
	{
		if(word1[i] != word2[i])
		{
			count++;  
		}
	} 
    /*  If the counter is equal to one, then returns true. If there are more than one differences 
        then return false */
	if(count == 1)
	{
		return true; 
	}
return false; 
}

/* This function returns the length of each word in the wordlist */
int graph::calc_len(string filename)
{
    ifstream input; 
    input.open(filename.c_str());  
    
    string word; 
    string line; 
    vector<string> words_vector;
    getline(input,word);
    int len = word.length(); 
    return len; 
}

/* This function reads the input word by word */
vector<string> graph::read_input(string filename)
{
    ifstream input; 
    input.open(filename.c_str());  
    
    string line; 
    vector<string> words_vector;
    while(input >> line)
    {
        words_vector.push_back(line);
    }
        return words_vector; 
}

/*  An adjecency list implementation of the graph is created 
    Each of the two words are checked if they differ by one letter. 
    Then if they are an edge is added. That is, the words are added 
    to the adjecency list. 
*/
map<string,vector<string> > graph::create_graph(vector<string> wordlist)
{
    map<string,vector<string> > adjacency_list;
    map<int,vector<string> >  temp_words;
    map<int,vector<string> >::const_iterator i;

    /* Populate at temporary list to compare and create a graph */
    for( int i = 0; i < wordlist.size( ); i++)
    {
        temp_words[wordlist[i].length()].push_back(wordlist[i]);
    }

    for( i = temp_words.begin(); i != temp_words.end(); ++i )
    {
        /* Two for loops to check word 1 and word 2 */
        const vector<string> & temp1 = i->second;
        for( int i = 0; i < temp1.size(); i++ )
        {
            for( int j = i + 1; j < temp1.size();j++)
            {
                /* If the two words differ by only one letter, then add to the adj list */
                if( compare_characters( temp1[i], temp1[j]))
                {
                    adjacency_list[temp1[i]].push_back(temp1[j]);
                    adjacency_list[temp1[j]].push_back(temp1[i]);
                }
            }
        }
        /* Returns the final adjecency list of words */   
        return adjacency_list;
    }
}

/* The get_path_BFS() uses Breadth First Search algorithm 
I used the following Algorithm to implement BFS 
procedure BFS(G,v) is
      create a queue Q
      create a set V
      add v to V
      enqueue v onto Q
      while Q is not empty loop
         t <- Q.dequeue()
         if t is what we are looking for then
            return t
        end if
        for all edges e in G.adjacentEdges(t) loop
           u <- G.adjacentVertex(t,e)
           if u is not in V then
               add u to V
               enqueue u onto Q
           end if
        end loop
     end loop
     return none
 end BFS
*/

vector<string> graph::get_path_BFS(const map<string,vector<string> > & adj_list, const string & first, const string & second )
{
    /* Stores the word and the path from source to destination */
    map<string,string> temp_list;
    
    queue<string> que;
    que.push(first);
    /* While the queue is not empty perform BFS */
    while(!que.empty())
    {
        /* Pop the first element in the queue */
        string present = que.front(); 
        que.pop();
        map<string,vector<string> >::const_iterator i;
        
        /* Start the iterator to extract the first element */
        i = adj_list.find(present);
        
        if( i != adj_list.end())
        {
            /* Get the adjecent vertex */
            const vector<string> & temp2 = i->second;
            /* Go through the entire list and check if its present*/
            for( int i = 0; i < temp2.size(); i++ )
            {
                if( temp_list[temp2[i]] == "")
                {
                    /* Add element through the queue and store it the path list*/
                    temp_list[temp2[i]] = present;
                    que.push(temp2[i]);
                }
            }
        }
    }
    
    temp_list[first] = "";
    /* Since BFS stores everything in reverse order, reverse the entire queue to get the correct path*/
    return reverse_path(temp_list,first,second);
}


/* This function reverses the vector obtained in the BFS Search to print the path and return the final list*/
vector<string> graph::reverse_path(const map<string,string> & adj_list, const string & first, const string & second)
{
    map<string,string> & temp_list = const_cast<map<string,string> &>(adj_list);
    vector<string> final_list;
    
    if(temp_list[second]!= "" )
    {
        string temp = second;
        while( temp != "" )
        {
            final_list.push_back(temp);
            temp = temp_list[temp];
        }
    }
    reverse(final_list.begin(),final_list.end());
    return final_list;
}

/* Recursive call to the breadth first search for each pair of words */
vector<string> graph::get_path_BFS(const vector<string> & adj_list,const string & first, const string & second )
{
    map<string,vector<string> > graph = create_graph(adj_list);
    return get_path_BFS(graph, first, second );
}
