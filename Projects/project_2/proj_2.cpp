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

    /// @brief Destructor for linked_list_movies
    ~linked_list_movies() {
        node* temp = head;
        while (temp != nullptr) {
            head = temp->next;
            delete temp;
            temp = head;
        }
    }

    /// @brief Displays movie IDs within current linked list
    void display(){
        node* curr_ptr = head;
        while (curr_ptr != nullptr) {
            cout <<" " << curr_ptr->data;
            curr_ptr = curr_ptr->next;
        }
        return;
    }

    /// @brief Checks to see if a movie has been watched within LL of movie IDs
    /// @param target_movie (int): ID of movie to be searched for
    /// @return (bool): true if watched; false if not watched
    bool has_watched(int target_movie) {
        bool watched = false;
        node* curr_ptr = head;
        while (curr_ptr != nullptr) {
            if (curr_ptr->data == target_movie) {
                watched = true;
            }

            // FUCK THIS LINE IN PARTICULAR!!!!!!
            curr_ptr = curr_ptr->next;
        }
        return watched;
    }
};

/// @brief customer class
class customer{
    public:

    int customer_id;
    linked_list_movies movie_ids;    

    /// @brief constructor
    /// @param id (int): Customer ID
    /// @param arr (vector<int>): Movie IDs watched by customer
    customer(int id, vector<int> arr){
        customer_id = id;

        // Insert movie IDs from vector into Movie LL
        for(int i = 0; i < arr.size(); i++){
            movie_ids.insert(arr.at(i));
        }
    }

    /// @brief Displays customer ID and movie IDs for specific customer object
    void display(){
        cout << "Customer " << customer_id << " watched";
        movie_ids.display();
        cout << endl;
        return;
    }
};

/// @brief Linked List of Pointers to customer objects
class linked_list_customers : public linked_list<customer*>{

    public:
    /// @brief Destructor to deallocate memory
    ~linked_list_customers() {
        node* temp = head;
        while (temp != nullptr) {
            head = temp->next;
            delete temp->data;
            delete temp;
            temp = head;
        }
    }

    /// @brief Seeks out customer ID and prints relevant info
    /// @param target_id (int): Customer ID
    void print_customer(int target_id){
        node* curr_ptr = head;

        while (curr_ptr != nullptr) {
        
            // if IDs match, display data
            if (curr_ptr->data->customer_id == target_id) {
                curr_ptr->data->display();
            }
            curr_ptr = curr_ptr->next;
        }

    }

    /// @brief Prints all customer data, alongside movies watched
    void print_all(){
        node* curr_ptr = head;

        while (curr_ptr != nullptr) {
            curr_ptr->data->display();
            curr_ptr = curr_ptr->next;
        }
    }

    /// @brief Prints views for specified movie
    /// @param target_id (int): Movie ID
    void print_views(int target_id){
        int count = 0;
        node* curr_ptr = head;

        while (curr_ptr != nullptr) {
            if (curr_ptr->data->movie_ids.has_watched(target_id)) {
                count ++;
            }
            curr_ptr = curr_ptr->next;
        } 

        // Formatted output
        cout << "Movie " << target_id << " has been watched " << count << " time(s)." << endl;
    }

    /// @brief Loads customers from text file into linked lists/customer pointers
    /// @param filename (string): Filename
    void load_customers(string filename){

        // Opening file input stream
        ifstream file_id(filename);
        
        // Variable declarations
        string line;
        int value;
        bool cust_id = true;
        bool movie_count = false;
        int count = 0;
        int i = 0;
        int c_id;
        vector<int> movies;

        // Executes while new lines can be read in
        while (getline(file_id,line)){

            // Converts text data into integer
            value = stoi(line);          

            // Reads in customer ID
            if (cust_id == true) {
                c_id = value;
                cust_id = false;
                movie_count = true;
            }

            // Reads in movie count
            else if (movie_count == true) {
                count = value;
                movie_count = false;
            }

            // Reads in movie IDs as long as count hasn't been reached
            else if (i < count) {
                movies.push_back(value);
                i++;    
                
                // Inserts customer pointer with data into linked list when all
                // movie data has been read in
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