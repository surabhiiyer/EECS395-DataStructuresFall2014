//
//  SpellCheck.cpp
//  DS_Proj3_v1
//
//  Created by Surabhi Ravishankar  on 11/22/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

#include <string>
#include <iostream>
#include "Dictionary.h"
#include "SpellCheck.h"

using namespace std;
/* All the functions use the substr() built in function to implement the SpellCheck Algorithm */

/* 
	Check Insert works by inserting a letter (a - z) between each of the letters of the word. 
	At each instance, It performs a lookup in the dictionary and return if the word is present. 
*/
string SpellCheck::CheckInsert(string word, int x, string letter) //, int x, string letter)
{ 		
	string new_word = word.substr(0, x) + letter + word.substr(x);
	return new_word; 
}
/* 
	Check Replace works by replacing each character in the word with a letter from a - z between each of the letters of the word. 
	At each instance, It performs a lookup in the dictionary and returns if the word is present. 
*/
string SpellCheck::CheckReplace(string word, int x, char letter)
{
	string new_word = word; 
	new_word[x] = letter; 
	return new_word;
}
/*	
	CheckSwap works by replacing adjecent characters of the input word and returns when the word is found in the dictionary. 
*/
string SpellCheck::CheckSwap(string word, int x)
{	
	string new_word = word.substr(0,x) + word[x+1] + word[x] + word.substr(x+2);
	return new_word; 
}

/*
	CheckDelete works by deleting each letter in the word and checking it against the dictionary hash table.  
*/
string SpellCheck::CheckDelete(string word, int x)
{
	string new_word = word.substr(0, x)+ word.substr(x + 1);
	return new_word;
}
