#ifndef _TEAM_
#define _TEAM_

#include "player.cpp"
#include <iostream>
#include <string>
#include <vector>

class team{
    private:
    vector <player*> _players;
    string _name = "";
    int _score = 0;

    public:
    team(string n = "NAME MISSING"){
        set_name(n);
    }

    void set_name(string n) {
        _name = n;
    }

    void set_score(int s) {
        _score = s;
    }

    string get_name() {
        return _name;
    }

    int get_score() {
        
        // Error handling to ensure total isn't bugged
        try{
            int s = _score;
            if (s >= 0){
                return _score;
            }
            else {

                // Throws error if score is negative
                throw (s);
            }
        }
        catch (int t) {
            cout << "ERROR: Total score is less than 0" << endl;
            cout << "Total Score: " << t << endl;
            exit(EXIT_FAILURE);
        }
    }

    void add_player(player* obj, int status) {
        if (status == 1) {
            clear_captain();
            cout << "Captain of " << get_name() << " specifed as: " << obj->get_name() << endl;
        }
        _players.push_back(obj);
        obj->set_status(status);
    }

    void clear_captain() {
        if (_players.size() > 0){
            for (int i = 0; i < _players.size(); i++){
                _players[i]->set_status(0);
            }
        }
    }

    void play_turn() {
        try{
            if (_players.size() > 0) {
                int sum = 0;
                for (int i = 0; i < _players.size(); i++){
                    _players[i]->play_turn();
                    sum+= _players[i]->get_score();
                }
                set_score(sum);
            }
            else{
                throw 1;
            }
        }
        catch(int i) {
            cout << "ERROR: Team has no players. Cannot play turn" << endl;
            cout << "Please add players." << endl;
            exit(EXIT_FAILURE);
        }
    }


};

#endif