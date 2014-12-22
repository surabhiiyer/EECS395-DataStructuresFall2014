//
//  HashTable.h
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

#include <stdio.h>
#include <string>

using namespace std;

class HashTable {
private:
      int key;
      string value;
	  bool present;
public:
      HashTable(int k, string val, bool exists);
      int get_key();
      string get_val(); 
	  bool check_present();
};
