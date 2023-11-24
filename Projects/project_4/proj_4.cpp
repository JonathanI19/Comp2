#include <iostream>
#include <fstream>
#include "./util.h"
#include <vector>
#include "./hash_table.cpp"
#include "./binary_tree.cpp"

using namespace std;

// Global object vars
hashTable tracklist;
binaryTree setlist;

// Global var for linecount
int linecount = 0;

/// @brief Loads song data from text file into hash table and binary search tree
/// @param file_name (string) name of text file with song list
void load_txt(string file_name, int argc, char *argv[]) {

    // Open up file stream
    ifstream f_id;
    f_id.open(file_name, ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;

    // Get each line from file one at a time
    while(getline(f_id,line)){
        
        // Increment linecount
        linecount++;

        // split at comma (separates band name and song name)
        i_split = line.find(',');

        // Extract details from line
        band_name = line.substr(0,i_split);
        line.erase(0,i_split+2);
        song_title = line.substr(0,line.size()-1);

        // Put data into song struct
        song s(band_name, song_title);

        // Insert into tracklist and setlist
        if (argv[1] == string("1")) {
            tracklist.insert(s);
        }
        if (argv[1] == string("2")) {
            setlist.insert(s);
        }
    }

    // Close file stream
    f_id.close();

    return;
}

/// @brief Uses text file to search through hash table
/// @param file_name (string) name of text file with song list
void search_hash(string file_name){

    // Open up file stream
    ifstream f_id;
    f_id.open(file_name, ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;

    // Get each line from file one at a time
    while(getline(f_id,line)){

        // Split at comma (separates song and band name)
        i_split = line.find(',');

        // Extract details from line
        band_name = line.substr(0, i_split);
        line.erase(0,i_split+2);
        song_title = line.substr(0, line.size()-1);

        // Lookup song in hash table via band name and song title, w/display set to true
        tracklist.lookup(band_name, song_title, true);
    }

    // Close file stream
    f_id.close();
}

/// @brief Uses text file to search through binary tree
/// @param file_name (string) name of text file with song list
void search_bst(string file_name){

    // Open up file stream
    ifstream f_id;
    f_id.open(file_name, ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;

    // Get each line from file one at a time
    while(getline(f_id,line)){

        // Split at comma (separates song and band name)
        i_split = line.find(',');

        // Extract details from line
        band_name = line.substr(0, i_split);
        line.erase(0,i_split+2);
        song_title = line.substr(0, line.size()-1);

        // Lookup song in binary search tree via band name and song title, w/display true
        setlist.lookup(band_name, song_title, true);
    }

    // Close file stream
    f_id.close();
}

// Pass in arguments to effect whether BST or HT is used
/// @brief Main function
int main(int argc, char* argv[]){

    // Exit program if command line argument not passed in
    if (argc == 1) {
        cout << "Command line argument required for program execution." << endl;
        cout << "Pass in 1 for Hash Table" << endl;
        cout << "Pass in 2 for Binary Search Tree" << endl;
        exit(0);
    }

    // Exit program if invalid arg is passed in
    if (argv[1] != string("1") && argv[1] != string("2")) {
        cout << "Invalid arg" << endl;
        cout << "Pass in 1 for Hash Table" << endl;
        cout << "Pass in 2 for Binary Search Tree" << endl;
        exit(0);
    }

    // Location of text file
    string file_name = "/data/courses/ece_3822/current/project_4/songlist.txt";

    // Calls function to load txt file
    load_txt(file_name, argc, argv);

    // If arg is 1 for Hash Table, search_hash and provide relevant output
    if (argv[1] == string("1")) {

        // Call search_hash function
        search_hash(file_name);
            
        // Print out size of hash table and traversal count
        cout << "Stack size of Hash Table: " << sizeof(tracklist) << endl;
        double avg_ht = (double)tracklist.get_traversals()/(double)linecount;
        cout << "Average traversals of Hash Table: " << avg_ht << endl;
    }

    // If arg is 2 for Binary Search Tree, search_bst and provide relevant output
    if (argv[1] == string("2")) {

        // Call search_bst function
        search_bst(file_name);

        // print out size of binary search tree and traversal count and num of nodes
        cout << "Stack size of Binary Search Tree: " << sizeof(setlist) << endl;
        double avg_bst = (double)setlist.get_traversals()/(double)linecount;
        cout << "Average traversals of Binary Search Tree: " << avg_bst << endl;
        cout << "Number of nodes in Binary Search Tree: " << setlist.get_nNodes() << endl;
    }

    return 0;
}
