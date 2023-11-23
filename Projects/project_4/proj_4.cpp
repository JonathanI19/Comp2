#include <iostream>
#include <fstream>
#include "./util.h"
#include <vector>
#include "./hash_table.cpp"
#include "./binary_tree.cpp"

using namespace std;

hashTable tracklist;
binaryTree<song> setlist;

void load_hash(string file_name) {

    ifstream f_id;
    f_id.open(file_name, ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;

    while(getline(f_id,line)){

        // split at comma (separates band name and song name)
        i_split = line.find(',');

        // Extract details from line
        band_name = line.substr(0,i_split);
        line.erase(0,i_split+2);
        song_title = line.substr(0,line.size()-1);
        song s(band_name, song_title);

        tracklist.insert(s);
    }
    f_id.close();

    return;
}

void search_hash(string file_name){
    ifstream f_id;
    f_id.open(file_name, ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;

    while(getline(f_id,line)){

        i_split = line.find(',');
        band_name = line.substr(0, i_split);
        line.erase(0,i_split+2);
        song_title = line.substr(0, line.size()-1);
        tracklist.lookup(band_name, song_title, true);
    }
    f_id.close();
}

void load_bst(string file_name) {
    ifstream f_id;
    f_id.open(file_name, ios_base::in);

    string line;
    string band_name;
    string song_title;
    int i_split;

    while(getline(f_id,line)){
        i_split = line.find(',');
        band_name = line.substr(0, i_split);
        line.erase(0,i_split+2);
        song_title = line.substr(0, line.size()-1);
        song s(band_name, song_title);
        setlist.insert(s);
    }
}


int main(){

    string file_name = "/data/courses/ece_3822/current/project_4/songlist.txt";

    // load_hash(file_name);
    // search_hash(file_name);

    load_bst(file_name);
    setlist.print_all();


    return 0;
}
