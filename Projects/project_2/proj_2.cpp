#include<iostream>
#include<fstream>
#include "linked_list.h"
using namespace std;

#define DEFAULT_DIRECTORY "/data/courses/ece_3822/current/project_2/"
#define DEFAULT_FILENAME "dataFile1.txt"

// do not edit
string get_filename(int argc, char** argv){
    string filename = DEFAULT_DIRECTORY;
    
    // no command line inputs: use default
    if (argc == 1)
        filename += DEFAULT_FILENAME;

    // command line filename given
    else
        filename += (string) argv[1];
    
    return filename;
}

class linked_list_movies : public linked_list<int>{
    public:

    void display(){
        // WRITE CODE TO DISPLAY THE LIST OF MOVIES
    }
};

class customer{
    public:

    int customer_id;
    linked_list_movies movie_ids;    

    void display(){
        // WRITE CODE TO DISPLAY THE CUSTOMER AND MOVIES
    }

};

// note this a linked list of POINTERS to customers...
// that way you only every make one copy of each customer
// and simply place a pointer to that customer in the linked list

class linked_list_customers : public linked_list<customer*>{

    public:

    void print_customer(int customer_id){
        // WRITE THIS FUNCTION
    }

    void print_all(){
        // WRITE THIS FUNCTION
    }

    void print_views(int movie_id){
        // WRITE THIS FUNCTION
    }

    void load_customers(string filename){

        /*
        This code might be useful:
        ifstream    file_id(filename);
        string line
        int value;
        while (getline(file_id,line))
            value = stoi(line)          
        */

    }

};


int main(int argc, char** argv){

    string filename;
    filename = get_filename(argc,argv);

    linked_list_customers clients;
    clients.load_customers(filename);

    clients.print_all();
    clients.print_customer(724);
    clients.print_views(109); 

    return 0;
}