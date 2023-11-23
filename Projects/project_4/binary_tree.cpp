#include "./util.h"
#include <vector>
#include <iostream>
#include <fstream>

template<typename T>

class binaryTree{

    protected:
    class node{
        public:
        T data;
        node *left, *right, *up;   
        node(T d){
            data  = d;
            left  = nullptr;
            right = nullptr;
            up    = nullptr;
        }
    }; // end class node

    node *root;
    int nNodes;

    public:
    // constructor - no parameters
    binaryTree(){
        root   = nullptr;
        nNodes = 0;
    }    

    void insert(T d){

        int key = hash_function(d.artist, d.name);
        
        node *newNode   = new node(d);
        node *currPtr   = root;
        node *parentPtr = nullptr;

        int LR;

        // special case if tree is empty
        if (nNodes == 0)
            root=newNode;
        
        else{

            // find which node should be parent to newNode
            while (currPtr){
                parentPtr = currPtr;
                int curr_key = hash_function(currPtr->data.artist, currPtr->data.name);
                if (key < curr_key){
                    currPtr = currPtr->left;
                    LR = 0;
                }
                else{
                    currPtr = currPtr->right;
                    LR = 1;
                }
            }

            // connect newNode to parent
            newNode->up = parentPtr;
            if (LR==0)
                parentPtr->left = newNode;
            else
                parentPtr->right = newNode;

        }

        // increment number of nodes
        nNodes++;

    }

    T lookup (string str1, string str2, bool display = false) {
        int key = hash_function(str1, str2);

        string permutation1 = str1 + str2;
        string permutation2 = str2 + str1;

        T output("", "");

        return output;
    }

    void write_out(T s) {
        cout << "Artist: " << s.artist << "   Song: " << s.name << endl;
    }

    int hash_function(string str1, string str2) {
        string input = str1 + str2;
        int key = 0;

        for (int i = 0; i < input.length(); i++) {
            key += input[i];
        }
        return key;
    }


    void print_all(){
        print_all(root);
    }

    void print_all(node *currNode){
        if (currNode){
            print_all(currNode->left);
            cout << "Artist: " << currNode->data.artist << "     Song: " << currNode->data.name << endl;
            print_all(currNode->right);
        }
    }

    // search function
    // print all

}; // end class tree