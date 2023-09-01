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
#include<cmath>

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
    double product;
    string line;
    int val;
    vector<int> arr;
    int max1,max2;
    bool i;

    // Open file stream
    ifstream file_id(filename);
    
    // Read values from file into vector and calculate length and sum
    while (getline(file_id,line)){
        val = stof(line);
        n++;
        s+=val;
        arr.push_back(val);
    }

    // Call functions to calculate avg and determine two highest numbers
    avg = findMean(n,s);
    findMax2(arr, max1, max2);

    // Calculate root and determine if complex
    product = (double)max1*(double)max2;
    if (product >= 0) {
        i = false;
    }
    else {
        i = true;
        product = product * -1;
    }
    root = sqrt(product);
    
    // Disp results with formatting
    dispResults(avg, root, i);

    // Close file
    file_id.close();

    return 0;
}
