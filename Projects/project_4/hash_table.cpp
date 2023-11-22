#include "./util.h"
#include <vector>
#include <iostream>
#include <fstream>

class hashTable{
    private:
    int num_elements;

    const static int buff_len = 1000;
    vector <song> buffer[buff_len];

    public:

    hashTable(){
        num_elements = 0;
    }

    int hash_function(string str1, string str2){
        
        int key = 0;
        
        string input = str1 + str2;

        for (int i = 0; i < input.length(); i++) {
            key += input[i];
        }
        key %= 1000;
        return key;
    }

    void insert(song s){
        int key = hash_function(s.artist, s.name);
        buffer[key].push_back(s);
    }

    song lookup(string str1, string str2, bool display = false) {
        int key = hash_function(str1, str2);
        string permutation1 = str1+str2;
        string permutation2 = str2+str1;

        song output("", "");

        for(int i = 0; i < buffer[key].size(); i++){
            string compare_val = buffer[key][i].artist + buffer[key][i].name;
            if ((compare_val == permutation1) || (compare_val == permutation2)){
                if (display == true){
                    write_out(buffer[key][i]);
                }
                return buffer[key][i];
            }
        }
        cout << str1 << " " << str2 << ": Not found" << endl;
        return output;
    }

    void write_out(song s) {
        cout << "Artist: " << s.artist << "   Song: " << s.name << endl;
    }

};
