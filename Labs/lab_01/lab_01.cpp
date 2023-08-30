/*
Lab 01

@author
@contact
@date

Example:
    This file can be compiled by typing

    This file can be run by typing
*/


#include<iostream>
#include<fstream>
using namespace std;


int main(int argc, char** argv){

    // step 0 - you can ignore this bit
    string filename = "/data/courses/ece_3822/current/lab_01/data.txt";
    if (argc>1)
        filename = argv[1];

    // step 1 init variables
    int s = 0;
    int n = 0;
    double avg = 0;
    double var = 0;
    string line;
    int val;

    // step 2 open file
    ifstream file_id(filename);
    
    // step 3 read values from file
    // this is just an example to demonstrate syntax; modify as you deem necessary!
    while (getline(file_id,line)){
        val = stof(line);
    }

    // step 4 print value
    cout << "The average value is " << avg << endl;

    file_id.close();

    return 0;
}
