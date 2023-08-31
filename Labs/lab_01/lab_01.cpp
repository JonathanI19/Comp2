/*
Lab 01

@author Jonathan Isely
@contact tuf91237@temple.edu
@date 9/3/2023

Example:
    This file can be compiled by typing 
    make lab_01

    This file can be run by typing
    ./lab_01
*/


#include<iostream>
#include<fstream>
#include<vector>
#include "util.h"

using namespace std;


int main(int argc, char** argv){

    // Determine file
    string filename = "/data/courses/ece_3822/current/lab_01/data.txt";
    if (argc>1)
        filename = argv[1];

    // Variable initialization
    int s = 0;
    int n = 0;
    double avg = 0;
    double root = 0;
    string line;
    int val;
    vector<int> arr;
    int max1,max2;

    // Open file stream
    ifstream file_id(filename);
    
    // Read values from file into vector and calculate length and sum
    while (getline(file_id,line)){
        val = stof(line);
        n++;
        s+=val;
        arr.push_back(val);
    }

    // Call functions to calculate and display results
    avg = findMean(n,s);
    findMax2(arr, max1, max2);
    root = findRoot(max1, max2);
    dispResults(avg, root);

    // Close file
    file_id.close();

    return 0;
}
