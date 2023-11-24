#include "./util.h"
#include <vector>
#include <iostream>
#include <fstream>

/// @brief Hashtable class for use in storing song data
class hashTable{

    private:

    // Keeps track of the number of traversals
    int traversals;

    // Setting buff_len and declaring array of vectors of songs
    const static int buff_len = 1000;
    vector <song> buffer[buff_len];

    public:

    /// @brief hashTable constructor
    hashTable(){

        // Traversals is initiated at 0
        traversals = 0;
    }

    // Thought process for making order not matter is that when people search for songs online
    // they can put either song name or artist name first.
    /// @brief Compute hash key based off of song name and band name (Order doesn't matter)
    /// @param str1 (string) song/band name
    /// @param str2 (string) song/band name
    /// @return (int) hash key
    int hash_function(string str1, string str2){
        
        int key = 0;
        
        // Combine input strings into singular input
        string input = str1 + str2;

        // Compute key by summing ascii characters
        // Not the most complex method, but allows for easy song search
        for (int i = 0; i < input.length(); i++) {
            key += input[i];
        }

        // Modulus operation to ensure indexing is correct and return key
        key %= 1000;
        return key;
    }
    
    
    /// @brief Method to insert song into hash table
    /// @param s (song) song data
    void insert(song s){
        int key = hash_function(s.artist, s.name);

        // add song data to vector
        buffer[key].push_back(s);
    }
    
    /// @brief getter for traversal count
    /// @return (int) number of traversals
    int get_traversals() {
        return traversals;
    }

    // Can be searched in either order of song or artist.
    // Because we're primarily loading in from the text file, this shouldn't
    // actually come into play, but I wanted to make it work this way.
    /// @brief Function to lookup song and artist combos based upon input
    /// @param str1 (string) song/band name
    /// @param str2 (string) song/band name
    /// @param display (bool) True: Output results in terminal | False: No output
    /// @return (song) Song struct
    song lookup(string str1, string str2, bool display = false) {

        // Determine hash key
        int key = hash_function(str1, str2);

        // Get permutations for comparison checks
        string permutation1 = str1 + str2;
        string permutation2 = str2 + str1;

        // Initial output
        song output("", "");

        // 1 Traversal added to count for computing hash and entering vector at pertinent location
        traversals++;

        // Loop through the vector at buffer[key] until a song match is found
        for(int i = 0; i < buffer[key].size(); i++){

            // Concatenate current song struct data for comparison
            string compare_val = buffer[key][i].artist + buffer[key][i].name;

            // If either permutation is the same as compare_val, we have a match
            if ((compare_val == permutation1) || (compare_val == permutation2)){

                // Display results if display is true
                if (display == true){
                    cout << "Artist: " << buffer[key][i].artist << "   Song: " << buffer[key][i].name << endl;
                }

                // Add value of i to traversals to keep running count
                traversals += i;

                // Return song at buffer[key][i]
                return buffer[key][i];
            }
        }

        // Default output if nothing found
        cout << str1 << " " << str2 << ": Not found" << endl;

        // returns empty song struct
        return output;
    }

};
