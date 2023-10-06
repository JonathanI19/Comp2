#include<iostream>
#include<fstream>
#include "linked_list.h"
#include<vector>
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
        node* curr_ptr = head;
        while (curr_ptr != nullptr) {
            cout <<" " << curr_ptr->data;
            curr_ptr = curr_ptr->next;
        }
        return;
    }

    bool has_watched(int target_movie) {
        bool watched = false;
        node* curr_ptr = head;
        while (curr_ptr != nullptr) {
            if (curr_ptr->data == target_movie) {
                watched = true;
            }
            curr_ptr = curr_ptr->next; // FUCK THIS LINE IN PARTICULAR
        }
        return watched;
    }
};

class customer{
    public:

    int customer_id;
    linked_list_movies movie_ids;    

    // Constructor
    customer(int id, vector<int> arr){
        customer_id = id;
        for(int i = 0; i < arr.size(); i++){
            movie_ids.insert(arr.at(i));
        }
    }

    void display(){
        cout << "Customer " << customer_id << " watched";
        movie_ids.display();
        cout << endl;
        return;
    }

};

// note this a linked list of POINTERS to customers...
// that way you only every make one copy of each customer
// and simply place a pointer to that customer in the linked list

class linked_list_customers : public linked_list<customer*>{

    public:

    void print_customer(int target_id){
        node* curr_ptr = head;
        while (curr_ptr != nullptr) {
            if (curr_ptr->data->customer_id == target_id) {
                curr_ptr->data->display();
            }
            curr_ptr = curr_ptr->next;
        }

    }

    void print_all(){
        node* curr_ptr = head;
        while (curr_ptr != nullptr) {
            curr_ptr->data->display();

            curr_ptr = curr_ptr->next;
        }
    }

    void print_views(int target_id){
        int count = 0;
        node* curr_ptr = head;
        while (curr_ptr != nullptr) {
            if (curr_ptr->data->movie_ids.has_watched(target_id)) {
                count ++;
            }
            curr_ptr = curr_ptr->next;
        } 

        cout << "Movie " << target_id << " has been watched " << count << " time(s)." << endl;      

    }

    void load_customers(string filename){

        
        //This code might be useful:
        ifstream    file_id(filename);
        string line;
        int value;
        bool cust_id = true;
        bool movie_count = false;
        int count = 0;
        int i = 0;
        int c_id;
        vector<int> movies;

        while (getline(file_id,line)){
            
            value = stoi(line);          
            if (cust_id == true) {
                c_id = value;
                cust_id = false;
                movie_count = true;
            }
            else if (movie_count == true) {
                count = value;
                movie_count = false;
            }
            else if (i < count) {
                movies.push_back(value);
                i++;    
                
                if (i == count) {
                    customer* temp = new customer(c_id, movies);
                    this->insert(temp);
                    cust_id = true;
                    movies.clear();
                    i = 0;
                }
            }
        }
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