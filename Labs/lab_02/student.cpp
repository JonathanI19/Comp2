/*
    Student utility file

    @Author: Jonathan Isely
    @Contact: jonathan.isely@temple.edu
    @Date: 9/10/2023
*/

#include<vector>
#include<string>
#include "student.h"
#include<bits/stdc++.h>
using namespace std;

// Constructor
student::student() {
    total = 0;
    count = 0;
}

// Name Setter
void student::set_name(string n) {
    name = n;
}

// Add grade
void student::add_grade(int val) {
    grades.push_back(val);
    count++;
    total += val;
}

// Max getter
int student::get_max() {
    if (count == 0) {
        cout << "{ERROR: No grades entered.}  ";
        return 0;
    }
    else{
        sort(grades.begin(), grades.end(), greater<int>());
        return grades.at(0);
    }
}

// Get Avg
double student::get_average() {
    if (count == 0) {
        cout << "{ERROR: No grades entered.}  ";
        return 0;
    }
    else{
        double avg = (double)total/(double)count;
        return avg;
    }
}

// Display method
void student::display() {
    cout << name << ": " << endl;
    for(int i = 1; i <= count; i++){
        cout << "Grade " << i << ": " << grades.at(i-1) << endl;
    }
}


