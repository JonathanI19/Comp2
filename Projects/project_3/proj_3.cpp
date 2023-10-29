/* PROJECT 3 - proj_3.cpp

    @author Jonathan Isely
    @contact jmisely19@gmail.com
    @date 10/29/2023

    Implements a system that models reading data asynchronously from the cloud,
    storing it temporarily in a buffer, and then placing it into a hash table.

    Compile:
        make all
    Compile for debug:
        make debug
    Run:
        ./proj_3 [OPT]
        where [OPT] is 1, 2, or 3 depending on which test case you are running.

*/
#include<iostream>
#include<thread>
#include<fstream>
#include<vector>
#include<deque>
#include<chrono>
#include<mutex>
#include "math.h"
using namespace std;
using namespace std::chrono;


/// @brief Student Struct
struct student{

    string first_name, last_name, major;
    float gpa;
    int ID;
};

// YOUR CODE HERE
class hashTable{
    private:
    int num_elements;

    // 51971 is a prime number that we can use as a length for our hash_function. This is a temporary band-aid.
    // Ideally, each member in the hash table would be a linked list node so we can start
    // off much smaller and dynamically handle collisions. However, for the sake of brevity
    // I will have to hold off on implementing that.
    const static int buff_len = 51971;
    student* buffer[buff_len];

    /// @brief Generates hash key based off of multiplication method of hashing
    /// @param id (int) ID from relevant student object
    /// @return (int) Computed Hash Key
    int hash_function(int id){

        // Fractional value between 0 and 1
        float c = 0.458762346;

        // Get fractional part of id*c
        float k = (float)id*c;
        k = k-(long)k;

        // Multiply buff_len by fractional part and round down.
        int val = floor((float)buff_len * k);
        return val; 
    }


    void collision_handler(student* s, int key){
        int start = key;

        if (buffer[key] == nullptr){
            buffer[key] = s;
        }
        else {
            while(buffer[key] != nullptr){
                key = key + 1 % buff_len;
                if (start == key) {
                    cout << "Hash table full" << endl;
                    return;
                }
            }
            buffer[key] = s;
        }
    }
    
    public:

    /// @brief Constructor
    hashTable(){
        num_elements = 0;
        
        // Setting each value of buffer to nullptr
        for (int i = 0; i < buff_len; i++){
            buffer[i] = nullptr;
        }
    }

    void insert(student* s){
        
        // Error handling for if hash table is full
        if (num_elements == buff_len) {
            cout << "Hash Table Full" << endl;
            return;
        }


        int key = hash_function(s->ID);

        // Insert w/Collision handling
        collision_handler(s, key);


    }



};

/// @brief Class used to store incoming data in queue to be popped off as needed
class queue{

    private:
    // Variable declarations
    deque<student*> student_queue;
    int num_elements;
    bool isEmpty;
    student* temp;

    public:
    /// @brief Constructor
    queue(){
        num_elements = 0;
        bool isEmpty = true;
    }

    /// @brief Insert pointer to student object into queue
    /// @param t (student*) Pointer to student object
    void insert(student* t){
        student_queue.push_back(t);
        num_elements++;
        isEmpty = false;
    }

    /// @brief Pop student pointer off front of queue
    /// @return (student*) Pointer to student object
    student* pop(){

        temp = student_queue.front();
        student_queue.pop_front();
        num_elements--;
        if (num_elements == 0) {
            isEmpty = true;
        }
        return temp;
    }

    /// @brief Checks to see if queue is empty
    /// @return (bool) True if empty; False if populated with data
    bool is_empty(){
        return isEmpty;
    }

};

// You will need these global variables
queue waiting_list;
hashTable student_db;
mutex queue_mutex;

// this controls the input timing. do not edit
bool stop_thread = false;
steady_clock::time_point t1 = steady_clock::now();
float t_elapsed(){
    return duration_cast<seconds>(steady_clock::now() - t1).count();
}


void process_input_data(){
    student* p_student;

    while (!stop_thread){
        queue_mutex.lock();

        // YOUR CODE HERE
        // Checking the queue
        // If there's data, remove it from the queue and
        // add it to the hash table

        queue_mutex.unlock();
    }
}

void load_data(string filename){
    string shared_path = "/data/courses/ece_3822/current/project_3/";
    string filename_complete = shared_path + filename;

    // create local variables to stash the data for each person as it's
    // read from the file
    float arrival_time,gpa;
    string first,last,major;
    int id;

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    // start the thread that will wait for input data to arrive
    thread thr(process_input_data);

    clock_t t_start = clock();
    while (f_id >> arrival_time){
        // read data for the next person in the file
        f_id >> first;
        f_id >> last;
        f_id >> gpa;
        f_id >> id;
        f_id >> major;

        // wait until their data packet has 'arrived'
        while ( t_elapsed() < arrival_time){
            ;
        }

        // Create new student object from struct
        student temp_student;
        temp_student.first_name = first;
        temp_student.last_name = last;
        temp_student.gpa = gpa;
        temp_student.ID = id;
        temp_student.major = major;
        
        // Generate pointer to student and allocate on heap
        student *p_student = &temp_student;
        new(p_student) student;


        queue_mutex.lock();

        // YOUR CODE HERE
        waiting_list.insert(p_student);

        queue_mutex.unlock();

    }

    f_id.close();                       // close the data file
    
    while (!waiting_list.is_empty()){   // wait for the waiting_list queue
        ;                               // to empty out before stopping the 
    }                                   // process_input_data thread

    stop_thread = true;                 // send a signal to the thread to stop running
    thr.join();                         // wait for the thread to finish up
}

int main(int argc, char** argv){
    string filename;

    if (argc !=2 ){
        cout << "ERROR: include a command line arguement of 0, 1, or 2" << endl;
        return -1;
    }

    switch (stoi(argv[1])){
        case 0: filename = "student_data_short.txt"; break;
        case 1: filename = "student_data_medium.txt"; break;
        case 2: filename = "student_data.txt"; break;
    }

    load_data(filename);

    // now that the data has been stored in the hash table, lets test hashtable lookup
    // if the student is found, print all their info
    // if not, print <student name> "not found"

    // YOUR CODE HERE FOR TESTING THE SEARCH/LOOKUP capability

    // search for the following student IDs
    // 427980112
    // 258399712
    // 948140115

    return 0;
}