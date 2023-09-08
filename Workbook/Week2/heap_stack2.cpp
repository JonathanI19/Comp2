#include<iostream>
using namespace std;

void f1(){
    int *p;
    p = new int;
    *p = 123;
    cout << *p << endl;
    cout << p << endl;

    // allocate on stack
    // technically x is a pointer
    int x[5];
    int array_offset = 3;
    int *pointer_to_array = x + array_offset;

    int *ptr = new int(10);
    *ptr = 1;
    *(ptr+1) = 2;
    ptr[2] = 3;
    cout << *ptr << endl;
    cout << *(ptr+1) << endl;
    cout << "printing contents of array w/ size 10" << endl;
    for (int i = 0 ; i<10 ; i++){
        cout << ptr[i] << "\t" << *(ptr+i) << endl;
    }

    int y = 5;
    int *ptr_to_y = &y;

}

void f2(){
    int *p = new int(10);
    int q[10];
    delete [] p;
}

int* f3(){
    int *p = new int(10);
    return p;
}

int main(){

    f1();
    f2();
    int *ptr = f3();
    ptr[0] = 123;
    ptr[1] = 456;
    delete [] ptr;
    
    return 0;
}