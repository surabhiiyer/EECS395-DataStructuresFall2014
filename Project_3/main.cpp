//
//  main.cpp
//  DS_Proj3_v1
//
//  Created by Surabhi Ravishankar  on 11/22/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <time.h>

#include "main_func.h"

void create_dictionary(); 
void Perform_SpellCheck(); 
void disp_input(); 
void sort_display(int count, string remove_dup[]);

int main(int argc, const char * argv[]) 
{

    clock_t init, final;

    string input_word; 
    ifstream input_list;
    ifstream context;
    
    if(argc < 2) 
    {
	cout << "\n" << "Please run the program like this: "<<"\n"<<"./spellcheck <InputFileName>"<<"\n"<<endl; 
    }
    else
    {
    string input_file_name = argv[1]; 
    cout << "Adding Words to the Dictionary " << endl; 
    cout << "Starting Timer...This might take some time. " << endl; 
    /*  Starting timer */ 
    init=clock();

    input_list.open("Program3Fall2014wordlist");

    while (input_list>>input_word)
    {
        if (isdigit(input_word[0]) == 0)
        {
            if (isupper(input_word[0]) == 0)
            {
                input_word[0] = tolower(input_word[0]);
            }

    /*  Function Call to the dictionary to add the words. Calls the add function of the dictionary
        hash table 
    */
        dic.add(input_word);
    }
    }
    input_list.close();

    /*  Ending timer  */ 
    final=clock()-init;
    cout << "Time Taken: "; 
    /*  Printing time in seconds  */ 
    cout << (double)final / ((double)CLOCKS_PER_SEC)<<" seconds"<<endl; 
    /* Displays the input as given in the question. */
    disp_input(input_file_name); 
    /*  Call to the functon defined in the main_func.h
        The spell check algorithms are called in this function 
    */
    Perform_SpellCheck(input_file_name); 
}
}

