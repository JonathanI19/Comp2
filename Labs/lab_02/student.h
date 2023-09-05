/*
    Student utility file header

    @Author: Jonathan Isely
    @Contact: jonathan.isely@temple.edu
    @Date: 9/10/2023
*/

#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<vector>
using namespace std;

/// @brief Class containing grade information for a student
class student{

    private:
    /// @brief name of student
    string name = "NAME_PENDING";
    /// @brief Vector of grades
    vector<int> grades;
    
    int total, count;

    public: 
    // Empty Constructor
    student();

    /// @brief Name setter
    /// @param n (string) Student's Name
    void set_name(string);

    /// @brief Adds a new grade to vector
    /// @param val (int) Grade
    void add_grade(int);

    /// @brief Gets max grade in vector
    /// @return (int) Maximum value in vector
    int get_max();

    /// @brief Gets average grade in vector
    /// @return (double) Average grade
    double get_average();

    /// @brief Displays formatted values for each grade
    void display();

};

#endif 