//
//  HashTable.cpp
//  DS_Proj3_v1
//
//  Created by Surabhi Ravishankar  on 11/22/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

/*	Consists of the HashTable entries which allow you to get values 
	and check if the values are present 

	Implements 3 functions, 
	1. get_key();  
	2. get_val(); 
	3. check_present(); 

*/

#include <iostream>
#include "HashTable.h"

using namespace std; 

HashTable::HashTable(int key, string value, bool present) {
            this->key = key;
            this->value = value;
	    	this->present = present;
      }
int HashTable::get_key()
{
	return key; 
}
string HashTable::get_val()
{
	return value; 
}

bool HashTable::check_present()
{
	return present; 
}
