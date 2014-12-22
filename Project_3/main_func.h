//
//  main_func.h
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

#include "Dictionary.h" 
#include "SpellCheck.h"

void create_dictionary(); 
void Perform_SpellCheck(); 
void disp_input(); 
void sort_display(int count, string remove_dup[], int found); //, int replace_fail_count, int swap_fail_count, int delete_fail_count);
bool check_duplicates(string found_words[1000]); 

Dictionary dic;
SpellCheck sc; 

void create_dictionary()
{
    clock_t init, final;

    string input_word; 
    ifstream input_list;
    ifstream context;
    
    cout << "Adding Words to the Dictionary " << endl; 
    cout << "Starting Timer... " << endl; 
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
            dic.add(input_word);
        }
    }

    input_list.close();
    final=clock()-init;
    cout << "Time Taken: "; 
    cout << (double)final / ((double)CLOCKS_PER_SEC)<<" seconds"<<endl; 
}

void disp_input(string filename)
{
string line;
ifstream input_file(filename.c_str());

if (input_file.is_open())
{
    cout <<"\n"<<"INPUT: "; 
    while ( getline (input_file,line) )
    {
       cout << line << '\n';
    }
    input_file.close();
} 

else 
{
    cout << "ERROR: Unable to Open the File"; 
}
}

void Perform_SpellCheck(string input_file_name) 
{

    int w_len  = 0;                     //length of the word 
    int count = 0; 
    int n = 0;

    int sz = 256; 

    /*  Add values to a string array everytime it is found */
    string* remove_dup = new string [sz]; 

    ifstream file;
    file.open(input_file_name.c_str());
    string word;
    while (!file.eof())
    {

    int rem = 0;
    int found = 0; 
    file >> word; 
    
    w_len = word.length();
    string remove_dup[300]={""};
    string remove_duped[300]={""};    
    
    /* Get Rid of the Delimiters */
    for(int i=0, len = word.length(); i<len; i++)
    {
        if(ispunct(word[i]))
        {
            word.erase(i--,1); 
            len = word.length(); 
        }
    }

    /* Convert the Words to Lower Case */
    for(int i = 0; i<word.length(); i++)
    {
        if(isupper(word[i]) == true)
        {
             word[i] = tolower(word[i]);  
        }
    }

    /* Start the Search Function */
    if(dic.lookup(word) != true)
    {
        string temp_word = word; 
        transform(temp_word.begin(), temp_word.end(), temp_word.begin(), ::toupper);
        cout << "\n" <<temp_word << " Not Found" << endl;
        string letter; 
        int count = 0; 
        int w_len = word.length(); 

        cout <<"Perhaps you meant: "<<endl; 
        
        /* Check by Insertion Algorithm */
        for(int i = 0; i < w_len; i++)
        {
            for(int c = 'a'; c<= 'z'; c++)
            {
                string letter(1,c);
                // Function Call CheckInsert
                string new_word = sc.CheckInsert(word,i,letter); 
                if(dic.lookup(new_word) == true)
                {
                    string temp_word1 = new_word; 
                    transform(temp_word1.begin(), temp_word1.end(), temp_word1.begin(), ::toupper);
                    remove_dup[rem] = temp_word1;
                    rem++;
                    found++; 
                } 
            }
        }  

        /* Check by Replacement Algorithm */
        for(int i = 0; i < w_len; i++)
        {
            for(int c = 'a'; c<= 'z'; c++)
                {
                    // Function call to check by replacement 
                    string replaced_word= sc.CheckReplace(word,i,c); 
                    if(dic.lookup(replaced_word) == true)
                    {
                    string temp_word2 = replaced_word; 
                    transform(temp_word2.begin(), temp_word2.end(), temp_word2.begin(), ::toupper);
                    remove_dup[rem] = temp_word2;
                    rem++;
                    found++; 
                    } 
                }
        }     

        /* Check by Swapping Algorithm */
        for(int i = 0; i < w_len-1; i++)
        {
            // Function Call to check by Swapping 
            string swap_word = sc.CheckSwap(word, i); 
            if(dic.lookup(swap_word) == true)
            {
                string temp_word3 = swap_word; 
                transform(temp_word3.begin(), temp_word3.end(), temp_word3.begin(), ::toupper);
                remove_dup[rem] = temp_word3;
                rem++;
                found++; 
            }

        }        

        /* Check by deleting Algorithm */
        for(int i = 0; i < w_len; i++)
        {
            // Function Call to check by deleting 
            string deleted_word = sc.CheckDelete(word, i); 
            if(dic.lookup(deleted_word) == true)
            {
                string temp_word4 = deleted_word; 
                transform(temp_word4.begin(), temp_word4.end(), temp_word4.begin(), ::toupper);
                remove_dup[rem] = temp_word4;
                rem++; 
                found++; 
            } 
        } 

/* Displays the list of words in sorted order */
sort_display(rem,remove_dup, found); 

}
}
}   

/* Displays the list of fond words in sorted order */
void sort_display(int count, string remove_dup[], int found) 
{
    string sorted_array[300] = {""}; 

/* If the words are not found, prints that the word is not listed */
    if(found < 1)
    {
        cout<<"\t"<<"Can't find word in the Dictionary -- Algorithm CheckSplit Not Implemented "<<endl;
    }
    else 
    {
    for (int i = 0; i < count; i++)
        {   
            int c = 0;
            for (int j = 0; j < count; j++)
            {
                if (remove_dup[i] > remove_dup[j])
                {
                    c++;
                }
            }
            sorted_array[c] = remove_dup[i];
        }
        /* Printing the Sorted Array */
        for (int k = 0; k < count; k++)
        {
            cout<<"\t"<<sorted_array[k]<<endl;
        }        
    }
}



