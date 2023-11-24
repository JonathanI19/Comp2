#include "./util.h"
#include <vector>
#include <iostream>
#include <fstream>

/// @brief Binary tree class
class binaryTree {

    protected:

    /// @brief Node class
    class node{
        public:
        // Each node contains a vector member
        vector<song> data;

        // pointers to other nodes
        node *left, *right, *up;   

        /// @brief Constructor
        node(){

            // Set all values to nullptr to start
            left  = nullptr;
            right = nullptr;
            up    = nullptr;

        }
    }; // end class node

    node *root;
    int nNodes;
    int traversals;

    public:

    /// @brief Constructor
    binaryTree(){
        root   = nullptr;
        nNodes = 0;
        traversals = 0;
    }

    /// @brief Destructor
    ~binaryTree(){

        // Call destroy function
        destroy(root);
    }    

    /// @brief Getter for nNodes
    /// @return (int) Number of nodes in BST
    int get_nNodes(){
        return nNodes;
    }

    /// @brief Getter for traversal count
    /// @return (int) Number of traversals done in search
    int get_traversals() {
        return traversals;
    }

    /// @brief Function to insert data into BST
    /// @param d (song) Song data
    void insert(song d){

        // Get key from hash function
        int key = hash_function(d.artist, d.name);
        
        // Node declarations
        node *newNode   = new node();
        node *currPtr   = root;
        node *parentPtr = nullptr;
    

        int LR;

        // special case if tree is empty
        if (nNodes == 0) {

            // Create new node and insert first data set into root
            root=newNode;
            root->data.push_back(d);
            nNodes++;
        }

        else{

            // find which node should be parent to newNode
            while (currPtr){
                parentPtr = currPtr;

                // Get hash key for current node
                int curr_key = hash_function(currPtr->data[0].artist, currPtr->data[0].name);

                // If currptr hash key > insert key
                if (key < curr_key){
                    currPtr = currPtr->left;
                    LR = 0;
                }

                // If currptr hash key < insert key
                else if (key > curr_key){
                    currPtr = currPtr->right;
                    LR = 1;
                }

                // If currptr hash key is same as insert key
                else if (key == curr_key) {
                    LR = 2;
                    break;
                }
            }

            // connect newNode to parent
            newNode->up = parentPtr;

            // Point parent node to new node
            if (LR==0) {
                parentPtr->left = newNode;
                newNode->data.push_back(d);
                nNodes++;
            }
            else if (LR==1) {
                parentPtr->right = newNode;
                newNode->data.push_back(d);
                nNodes++;
            }

            // If key matches pre-existing node, push to back of vector and delete newNode as it isn't needed
            else {
                currPtr->data.push_back(d);
                delete newNode;
            }
        }
    }

    // Can be searched in either order of song or artist.
    // Because we're primarily loading in from the text file, this shouldn't
    // actually come into play, but I wanted to make it work this way.
    /// @brief Method to lookup songs within binary search tree
    /// @param str1 (string) song/band name
    /// @param str2 (string) song/band name
    /// @param display (bool) True: Output results in terminal | False: No output
    /// @return (song) song struct
    song lookup (string str1, string str2, bool display = false) {

        // Get hash key of input song
        int key = hash_function(str1, str2);

        // Determine both permutations for match comparisons
        string permutation1 = str1 + str2;
        string permutation2 = str2 + str1;

        // Default song output
        song output("", "");

        // Set currPtr to target root
        node *currPtr   = root;
        
        // Loop while currPtr is not nullptr
        while(currPtr){

            // set curr_key to key of currPtr
            int curr_key = hash_function(currPtr->data[0].artist, currPtr->data[0].name);
            
            // If lookup key < curr_key go to left ptr
            if (key < curr_key){
                currPtr = currPtr->left;
                traversals++;
            }

            // If lookup key > curr_key go to right of ptr
            else if (key > curr_key){
                currPtr = currPtr->right;
                traversals++;
            }

            // if keys match, search through vector for song and artist match
            else if (key == curr_key) {
                for (int i = 0; i < currPtr->data.size(); i++) {

                    // Determine compare value of item at current vector index
                    string compare_val = currPtr->data[i].artist + currPtr->data[i].name;
                    
                    // Check if current compare_value matches either of the permutations
                    if ((compare_val == permutation1) || (compare_val == permutation2)){

                        // Set output artist and name
                        output.artist = currPtr->data[i].artist;
                        output.name = currPtr->data[i].name;

                        // If display is true, write output to terminal
                        if (display)
                            write_out(output);

                        // increment traversals and return output
                        traversals += i;
                        return output;
                    }
                }
            }    
        }

        // If match not found, say so
        cout << str1 << " " << str2 << ": Not found" << endl;
        return output;
    }

    /// @brief Writes output to terminal
    /// @param s (song) song struct to be printed
    void write_out(song s) {
        cout << "Artist: " << s.artist << "   Song: " << s.name << endl;
    }

    // Thought process for making order not matter is that when people search for songs online
    // they can put either song name or artist name first.
    /// @brief Determines hash key based upon artist name and song name
    /// @param str1 (string) song/band name
    /// @param str2 (string) song/band name
    /// @return (int) hash key
    int hash_function(string str1, string str2) {

        // Combine input strings
        string input = str1 + str2;


        int key = 0;

        // Compute key by summing ascii characters
        // Not the most complex method, but allows for easy song search
        for (int i = 0; i < input.length(); i++) {
            key += input[i];
        }

        // return hash key
        return key;
    }

    /// @brief Prints all member nodes of binary search tree
    void print_all(){
        print_all(root);
    }

    /// @brief Prints all members of binary search tree
    /// @param currNode (node*) Pointer to starter node
    void print_all(node *currNode){

        // Recursively print out all ndoes
        if (currNode){
            print_all(currNode->left);
            for (int i = 0; i < currNode->data.size(); i++){
                cout << "Artist: " << currNode->data[i].artist << "     Song: " << currNode->data[i].name << endl;
            }
            print_all(currNode->right);
        }
    }

    /// @brief recursively destroys all nodes; Called by destructor
    /// @param tmp Starter node
    void destroy(node *tmp){
        if (tmp) {
            destroy(tmp->left);
            destroy(tmp->right);
            delete tmp;
        }
    }

}; // end class tree