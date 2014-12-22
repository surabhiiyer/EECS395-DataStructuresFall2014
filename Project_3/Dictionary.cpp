//
//  Dictionary.cpp
//  DS_Proj3_v1
//
//  Created by Surabhi Ravishankar  on 11/22/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

#include <iostream>
#include "Dictionary.h"

using namespace std;

/* Implementation of the hashCode as given in the Question */

unsigned int Dictionary::hashCode(const char*p, int len)
{
		  unsigned int h = 0;
		  for (int i = 0; i < len; i++)
          {
              h = (h<<5)||(h>>27);
              h += (unsigned int) p[i];
          }
		  return h;
}

/*  Dictionary Search Function 
    Algorithm: 
    while (table[probe] is occupied)
        if(table[probe] not present or table[proble] != search word)
            probe = (probe + offset) mod M
        else 
            found --> return true 
    return false     
*/

bool Dictionary::lookup(string search_word) 
{
    int probe = 0;
    int offset = 0;
    int word_len = search_word.size();
    const char* p = search_word.c_str();
    probe = hashCode(p, word_len) % TABLE_SIZE;
    offset = TABLE_R - (hashCode(p, word_len) % TABLE_R);
    while (dictionary_table[probe] != NULL)
    {
        if (dictionary_table[probe]->check_present() == false || dictionary_table[probe]->get_val() != search_word)
        {
            probe = (probe + offset) % TABLE_SIZE;
        }
        else
        {   
            return true;
        }
    }
 return false;
}

/*  Insertion using double hashing 
    Algorithm : 
    if(table is full) error
        probe = h1(K)
        offset = h2(K)
    while (table[probe] is occupied)
        probe = (probe + offset) mod M
    table[probe] = K
*/

void Dictionary::add(string word) {
		  
        int probe  = 0;
        int offset = 0;
        int word_len = word.size();
		  
        const char* p = word.c_str();
		  
        probe = hashCode(p, word_len) % TABLE_SIZE;
        offset = TABLE_R - (hashCode(p, word_len) % TABLE_R);
		  
        while (dictionary_table[probe] != NULL && dictionary_table[probe]->get_val() != word)
        {
              probe = (probe + offset) % TABLE_SIZE;
        }
		  
        dictionary_table[probe] = new HashTable(probe, word, true);
}

/*  Dictionary Remove Function 
    Algorithm: 
    while (table[probe] is occupied)
        if(table[probe] value not present or table[proble] != word)
            probe = (probe + offset) mod M
        else 
            table[probe] = NULL; 
    return false     
*/

void Dictionary::remove(string word)
{
        int probe = 0;
        int offset = 0;
        int stringLength = word.size();
        const char* p = word.c_str();
        probe = hashCode(p, stringLength) % TABLE_SIZE;
        offset = TABLE_R - (hashCode(p, stringLength) % TABLE_R);
    
        while (dictionary_table[probe] != NULL)
        {
            
           if (dictionary_table[probe]->check_present() == false || dictionary_table[probe]->get_val() != word)
            {
                  probe = (probe + offset) % TABLE_SIZE;
              
            } 
            else
            {
                dictionary_table[probe] = NULL;  
            }
        }
}