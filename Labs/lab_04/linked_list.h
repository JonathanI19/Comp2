#ifndef _linked_list_h_
#define _linked_list_h_

namespace ll_node{
    // node for the linked list data
    // do not edit
    class node{
        
        private:
        int data;
        node* next;

        public:
        
        // constructor
        node(int d){
            data = d;
            next = nullptr;
        };

        // getter, data
        int get_data(){
            return data;
        }

        // setter, 'next' pointer
        void set_next(node *n){
            next = n;
        }

        // getter, 'next' pointer
        node* get_next(){
            return next;
        }
    };
}

class linked_list{

    // private class variables
    private:

    ll_node::node* head;
    int n_elements;
    int total;

    // public class methods
    public:

    linked_list(){
        head = nullptr;
        n_elements = 0;
        total = 0;
    }

    void insert(int d){
        ll_node::node *newNode = new ll_node::node(d);
        newNode->set_next(head);
        head = newNode;
        n_elements++;
        total += d;
    }

    int pop(){
        int ret_val = 0;
        if (n_elements > 0){
            ret_val = head->get_data();
            total -= ret_val;
            ll_node::node *tmpNode = head;
            head = head->get_next();
            delete tmpNode;
            n_elements --;
        }
        return ret_val;
    }

    void clear_list(){
        while (n_elements > 0) {
            ll_node::node *tmpNode = head;
            head = head->get_next();
            delete tmpNode;
            n_elements--;
            total = 0;
        }
    }
    bool is_empty(){
        if (n_elements == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    int size(){
        return n_elements;
    }
    int sum(){
        return total;
    }
};

#endif