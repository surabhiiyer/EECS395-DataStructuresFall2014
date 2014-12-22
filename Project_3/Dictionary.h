//
//  Dictionary.h
//  DS_Proj3_v1
//
//  Created by Surabhi Ravishankar  on 11/22/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

#include <iostream>
#include "HashTable.h"

using namespace std; 

/* This is chosen from the prime number list that was provided to us */

const int TABLE_SIZE = 69997;
const int TABLE_R = 66529;

class Dictionary {
private:
      HashTable **dictionary_table;
public:

/*  Creating a Constructor to initialize the hash table */
Dictionary() 
{
    dictionary_table = new HashTable*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
    	dictionary_table[i] = NULL;
    }
}

/*  Creating a Destructor to Free the memory */
~Dictionary() 
{
    for (int i = 0; i < TABLE_SIZE; i++)
        if (dictionary_table[i] != NULL)
            delete dictionary_table[i];
    delete[] dictionary_table;
}

/*  Function definitons to create a basic hash table 
    1. add() --> adds values to the hash table using double hashing. 
    2. lookup() --> searches for spelling mistakes in the files.  
    3. remove() --> removes values from the hash table. 
*/
    
unsigned int hashCode(const char*p, int len); 
void add(string value); 
bool lookup(string value);
void remove(string value); 
};
