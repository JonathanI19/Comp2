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
    tree(){
        root   = nullptr;
        nNodes = 0;
    }    

    void insert(T d){

        int key = hash_function(d);
        
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
                if (d < currPtr->data){
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

    void hash_function(T s) {
        string input = s.artist + s.name;

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
            cout << currNode->data << endl;
            print_all(currNode->right);
        }
    }

    // search function
    // print all

}; // end class tree