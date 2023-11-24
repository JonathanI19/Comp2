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
void load_txt(string file_name) {

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
        tracklist.insert(s);
        setlist.insert(s);
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


int main(){

    // Location of text file
    string file_name = "/data/courses/ece_3822/current/project_4/songlist.txt";

    // Calls function to load txt file
    load_txt(file_name);

    // Calls functions to search through either hash table or binary search tree.
    // Comment out as needed so that only one is executed
    search_hash(file_name);
    search_bst(file_name);

    // Print out size of hash table and traversal count
    cout << "Stack size of Hash Table: " << sizeof(tracklist) << endl;
    double avg_ht = (double)tracklist.get_traversals()/(double)linecount;
    cout << "Average traversals of Hash Table: " << avg_ht << endl;

    // Print out size of binary search tree
    cout << "Stack size of Binary Search Tree: " << sizeof(setlist) << endl;
    double avg_bst = (double)setlist.get_traversals()/(double)linecount;
    cout << "Average traversals of Binary Search Tree: " << avg_bst << endl;
    cout << "Number of nodes in Binary Search Tree: " << setlist.get_nNodes() << endl;


    return 0;
}
