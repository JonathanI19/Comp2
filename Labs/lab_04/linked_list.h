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

/// @brief Linked list class - Inherits Node
class linked_list{

    // private class variables
    private:

    /// @brief pointer to the head
    ll_node::node* head;

    /// @brief num of current elements in linked list
    int n_elements;

    /// @brief sum of current data vals
    int total;

    // public class methods
    public:

    /// @brief Constructor - Sets head to nullptr
    linked_list(){
        head = nullptr;
        n_elements = 0;
        total = 0;
    }

    /// @brief Inserts data into new node in linked list and adjusts head
    /// @param d (int) - Data to be inserted
    void insert(int d){
        ll_node::node *newNode = new ll_node::node(d);
        newNode->set_next(head);
        head = newNode;

        // Increment num of elements and add d (int) to total
        n_elements++;
        total += d;
    }

    /// @brief Pops data from head out of the linked list
    /// @return (int) data from front node of list
    int pop(){
        int ret_val = 0;

        // Pop only list is populated
        if (n_elements > 0){

            // Get return val and remove data (int) from total
            ret_val = head->get_data();
            total -= ret_val;

            // point tmpnode to current head, shift head to next position, 
            // and then delete data that tmpnode points to
            ll_node::node *tmpNode = head;
            head = head->get_next();
            delete tmpNode;
            
            // Decrement num of elements
            n_elements --;
        }
        return ret_val;
    }

    /// @brief Clears list of all nodes
    void clear_list(){

        // Execute while list is populated
        while (n_elements > 0) {

            // Point tmpNode to current head, shift head to next position,
            // delete data that tmpNode points to
            ll_node::node *tmpNode = head;
            head = head->get_next();
            delete tmpNode;

            // Decrement n_elements
            n_elements--;
        }

        // Set total to 0 and return
        total = 0;
        return;
    }

    /// @brief Check if linked list is populated
    /// @return (bool) true if empty, false if populated
    bool is_empty(){
        if (n_elements == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    /// @brief Get number of nodes in linked list
    /// @return (int) num of nodes
    int size(){
        // ORIGINAL METHOD COMMENTED BELOW
        // return n_elements;


        // TESTING ALTERNATIVE METHOD - May be better encapsulation
        ll_node::node *current1 = head;
        int size_val = 0;
        while (current1 != nullptr)
        {
            // std::cout << current1->get_data() <<std::endl;
            current1 = current1->get_next();
            size_val++;
        }

        return size_val;
        // END OF ALTERNATIVE METHOD
    }

    /// @brief Return sum of data vals (ints) in linked list nodes
    /// @return (int) sum of data vals in nodes
    int sum(){
        // ORIGINAL METHOD COMMENTED BELOW
        // return total;

        // TESTING ALTERNATIVE METHOD - May be better encapsulation
        int new_total = 0;
        
        ll_node::node *temp = head;
        while (temp != nullptr) {
            new_total += temp->get_data();
            temp = temp->get_next();
        }
        return new_total;
        // END OF ALTERNATIVE METHOD

    }
};

#endif