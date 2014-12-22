//
//  SpellCheck.h
//  DS_Proj3_v1
//
//  Created by Surabhi Ravishankar  on 11/22/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//	

#include <string>
#include <iostream>

using namespace std;

/* 	This file contains the spell check class that consists of the function declarations. 
	I have implemented FOUR of the Algorithms, CheckInsert, CheckDelete, CheckReplace and Check Swap 
*/
class SpellCheck
{
public:
	string CheckInsert(string word, int x, string letter);
	string CheckSwap(string word, int x); 
	string CheckReplace(string word, int x, char letter);
	string CheckDelete(string word, int x);
};
