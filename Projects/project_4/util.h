#ifndef UTIL
#define UTIL

using namespace std;

struct song {
    string name;
    string artist;

    song(string a = "", string n = ""){
        name = n;
        artist = a;
    }
};

#endif