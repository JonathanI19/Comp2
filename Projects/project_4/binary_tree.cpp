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

        int key = hash_function(d.artist, d.name);
        
        node *newNode   = new node();
        node *currPtr   = root;
        node *parentPtr = nullptr;
    

        int LR;

        // special case if tree is empty
        if (nNodes == 0) {
            root=newNode;
            root->data.push_back(d);
            nNodes++;
        }

        else{

            // find which node should be parent to newNode
            while (currPtr){
                parentPtr = currPtr;
                int curr_key = hash_function(currPtr->data[0].artist, currPtr->data[0].name);

                if (key < curr_key){
                    currPtr = currPtr->left;
                    LR = 0;
                }

                else if (key > curr_key){
                    currPtr = currPtr->right;
                    LR = 1;
                }

                else if (key == curr_key) {
                    LR = 2;
                    break;
                }
            }

            // connect newNode to parent
            newNode->up = parentPtr;
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
            else {
                currPtr->data.push_back(d);
                delete newNode;
            }

        }

    }

    /// @brief 
    /// @param str1 
    /// @param str2 
    /// @param display 
    /// @return 
    song lookup (string str1, string str2, bool display = false) {
        int key = hash_function(str1, str2);

        string permutation1 = str1 + str2;
        string permutation2 = str2 + str1;

        song output("", "");
        node *currPtr   = root;

        while(currPtr){

            int curr_key = hash_function(currPtr->data[0].artist, currPtr->data[0].name);
            if (key < curr_key){
                currPtr = currPtr->left;
                traversals++;
            }

            else if (key > curr_key){
                currPtr = currPtr->right;
                traversals++;
            }

            else if (key == curr_key) {
                for (int i = 0; i < currPtr->data.size(); i++) {
                    string compare_val = currPtr->data[i].artist + currPtr->data[i].name;
                    if ((compare_val == permutation1) || (compare_val == permutation2)){
                        output.artist = currPtr->data[i].artist;
                        output.name = currPtr->data[i].name;
                        if (display)
                            write_out(output);

                        traversals += i;
                        return output;
                    }
                }
            }    
        }
        cout << str1 << " " << str2 << ": Not found" << endl;
        return output;
    }

    /// @brief
    /// @param s 
    void write_out(song s) {
        cout << "Artist: " << s.artist << "   Song: " << s.name << endl;
    }

    /// @brief 
    /// @param str1 
    /// @param str2 
    /// @return 
    int hash_function(string str1, string str2) {
        string input = str1 + str2;
        int key = 0;

        for (int i = 0; i < input.length(); i++) {
            key += input[i];
        }
        return key;
    }

    /// @brief 
    void print_all(){
        print_all(root);
    }

    /// @brief 
    /// @param currNode 
    void print_all(node *currNode){
        if (currNode){
            print_all(currNode->left);
            for (int i = 0; i < currNode->data.size(); i++){
                cout << "Artist: " << currNode->data[i].artist << "     Song: " << currNode->data[i].name << endl;
            }
            print_all(currNode->right);
        }
    }

    /// @brief 
    /// @param tmp 
    void destroy(node *tmp){
        if (tmp) {
            destroy(tmp->left);
            destroy(tmp->right);
            delete tmp;
        }
    }

}; // end class tree