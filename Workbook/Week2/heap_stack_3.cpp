#include<iostream>
using namespace std;

class buffer{
    private:
    int *buff;
    int buffSize;

    public:
    buffer(int N){
        buff = new int(N);
        buffSize = N;
    }
    ~buffer(){
        delete [] buff;
    }
    void check_my_size(){
        cout << sizeof(buff) << endl;
    }
};

int main(){
    buffer b1(10);
    buffer b2(100);
    b1.check_my_size();
    b2.check_my_size();
    return 0;
}