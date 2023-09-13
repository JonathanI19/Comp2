#ifndef _PLAYER_
#define _PLAYER_

/* this include gives you access to 
    int generate_score(int)
which takes ability (0,1,2) as input and returns a valid 
score according to the project instructions */
#include "ece_3822.h"
#include <cstring>
using namespace std;


/// @brief Player Object
class player{
    private:
    string _name = "NAME MISSING";
    int _score;
    int _ability;
    int _status = 0;

    public:

    player(string n = "", int a = -1){
        set_name(n);
        set_ability(a);
    }
    void set_name(string n){
        _name = n;
    }
    void set_score(int s){
        _score = s;
    }
    void set_ability(int a){
        _ability = a;
    }
    void set_status(int stat){
        _status = stat;
    }
    string get_name(){
        return _name;
    }

    int get_score(){
        try{
            int s = _score;
            if (s >= 0){
                return _score;
            }
            else {
                throw (s);
            }
        }
        catch (int s) {
            cout << "ERROR: Score is less than 0" << endl;
            cout << "Score: " << s << endl;
            exit(EXIT_FAILURE);
        }
    }
    
    int get_ability(){
        try{
            int a = _ability;
            if (a >= 0 && a <= 2) {
                return _ability;
            }
            else {
                throw (a);
            }
        }
        catch (int a) {
            cout << "ERROR: Ability must be set to integer value 0 - 2" << endl;
            cout << "Ability: " << a << endl;
            exit(EXIT_FAILURE);
        }

    }
    int get_status(){
        try{
            int s = _status;
            if (s == 0 || s== 1) {
                return _status;
            }
            else {
                throw(s);
            }
        }
        catch (int s) {
            cout << "ERROR: Invalid Status - Must be 0 for normal or 1 for captian" << endl;
            cout << "Status: " << s << endl;
            exit(EXIT_FAILURE);
        }
    }
    void reset_score(){
        set_score(0);
    }
    void play_turn(){
        for (int i = 0; i <= get_status(); i++){
            int current_score = get_score();
            current_score += generate_score(get_ability());
            set_score(current_score);
        }
    }
    void display() {
        cout << get_name() << ": " << get_score() << endl;
    }
        
};

#endif