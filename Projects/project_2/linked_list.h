template <typename T>
class linked_list{

    protected:
    struct node{
        T data;
        node* next;
        node(){next = nullptr;}
        node(T d){
            data = d;
            next = nullptr;
        }
    };

    int n_elements;
    node* head;

    public:

    // constructor
    linked_list(){
        head = nullptr;
        n_elements = 0;
    }

    // destructor # uncomment after project 2 is graded (IO 20231003)
    // ~linked_list(){
    //     while (n_elements > 0)
    //         pop();
    // }

    // insert at front of linked list    
    void insert(T d){
        node* new_node = new node(d);
        new_node->next = head;
        head = new_node;
        n_elements++;
    }

    // pop leading element off the linked list
    T pop(){
        T pop_data;
        node *pop_node = head;
        head = head->next;
        n_elements--;
        pop_data = pop_node->data;
        delete pop_node;
        return pop_data;
    }

    // get linked list length
    int len(){
        return n_elements;
    }

};

