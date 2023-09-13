#include<iostream>
using namespace std;

int main(){

    // my_array is a pointer to the first int of the array
    // *my_array is the same as my_array[0]
    // *(my_array + 1) is the same as my_array[1]
    int my_array[5];
    int *ptr_to_array = my_array;

    // my_array_of_pointers is a pointer to the first pointer-to-int of the array
    int *my_array_of_pointers[5];
    int **pointer_to_my_array_of_pointers = my_array_of_pointers;


    return 0;
}