#ifndef UTIL
#define UTIL

using namespace std;

/// @brief Song struct - Used to hold song data
struct song {
    string name;
    string artist;

    /// @brief Constructor for song struct
    /// @param a (string) artist name
    /// @param n (string) song name
    song(string a = "", string n = ""){
        name = n;
        artist = a;
    }
};

#endif