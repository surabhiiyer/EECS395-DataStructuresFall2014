//
//  main.cpp
//  DS_Proj2_v4
//
//  Created by Surabhi Ravishankar  on 11/9/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//

#include "functions.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

/* This is the main file which is used to read the input file from the user using 
   command line arguements
*/
int main(int argc, char *argv[]){

    if(argc < 2)
    {
        cout<<"INSUFFICIENT COMMANDLINE ARGUEMENTS "<<endl;
        cout<<"Execute as follows: ./Project2 filename.txt "<<endl;
    }
    else
    {
        string inpt;
        vector<string> inptvctr;
        ifstream f;
        f.open(argv[1]);
        while (getline(f, inpt))
        {
            istringstream istr(inpt);
            while( !istr.eof())
            {
                string tmp_s;
                istr >> tmp_s;
                if(tmp_s !="")
                {
				inptvctr.push_back(tmp_s);
                }
            }
		if(inptvctr.size()!=0)
            prcss(inptvctr);
            inptvctr.clear();
        }
	
        cout<<"\nEND\n";
        exit(0);
    }
    }
