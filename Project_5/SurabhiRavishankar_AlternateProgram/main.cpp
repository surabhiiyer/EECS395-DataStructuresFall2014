//
//  main.cpp
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

#include "graph.h"
#include "queue.h" 

using namespace std;

int main(int argc, char* argv[])
{

    graph g; 

	map<string,vector<string> > adjacency_list;
    vector<string> words;
    /* Reading the input from the given word list */
    cout << "WORD LADDER GAME" <<endl;
	words= g.read_input("Program4AlternativeFall2014words.txt");
    cout<<"Done Reading Input File..."<<endl; 
    cout << "Enter Ctrl + C to exit any time!!" << "\n" << endl; 

    /* Calculate the length of each word in the wordlist */
    int k = g.calc_len("Program4AlternativeFall2014words.txt"); 
   
    /* Create a graph using all the words */
    adjacency_list = g.create_graph(words);
    
	string word1; 
	string word2; 

    int ladder_len; 
	
    string terminate = "";
    while(true)
    {
        cout << "Enter the source word: " << endl;
        cin >> word1;
        cout << "Enter target word: "<< endl;
        cin >> word2;

        /* Perform BFS */
        vector<string> ladder = g.get_path_BFS(adjacency_list,word1,word2);

        ladder_len = ladder.size(); 

        int tot_len = ladder_len - 1;

        // if the steps exceed 6, then print cannot convert. since all the word list are 6 letters long. 
        if(tot_len == -1 || tot_len > k)
        {
            cout << "\n" <<"Cannot Convert!!!"<<"\n" ;
            cout << endl; 
        }
        else 
        {
            //cout << "\n" <<"Length of path = " << ladder_len - 1<<endl;
            cout << "\n" <<"Printing word Ladder: "<<endl; 
                for(int i = 0; i < ladder_len; i++)
                {
                    cout << ladder[i] << "\n";
                }
            cout << endl;  
        }
    }

}
