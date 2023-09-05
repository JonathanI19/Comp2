#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;


class student{

    private:

    string name;
    // ADD VARIABLES HERE AS NEEDED


    public:

    // DON'T CHANGE THESE FUNCTION PROTOTYPES
    student();
    void set_name(string);
    void add_grade(int);
    int get_max();
    double get_average();
    void display();

};

#endif 