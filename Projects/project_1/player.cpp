/*
player.cpp

@author Jonathan Isely
@contact tuf91237@temple.edu
@date 9/13/2023

Example:
    This file can be compiled by typing 
    make all

    This file can be run by typing
    ./play_game 1
*/

#ifndef _PLAYER_
#define _PLAYER_

/* this include gives you access to 
    int generate_score(int)
which takes ability (0,1,2) as input and returns a valid 
score according to the project instructions */
#include "ece_3822.h"
#include <string>
#include <iostream>
using namespace std;


/// @brief Generates Player Object
/// @param n (string) name to be passed into constructor
/// @param a (int) ability score to be passed into constructor
class player{

    private:

    /// @brief  (string) Name of player; Placeholder to show missing name in output
    string _name = "";

    /// @brief  (int) Running count of players score
    int _score;

    /// @brief (int) Represents players ability level; Expected Value: 0, 1, 2
    int _ability;

    /// @brief (int) Deneotes players and captains; 0(Default) = Player, 1 = Captain
    int _status = 0;

    public:

    // Constructor, accepts string and int
    player(string n = "NAME MISSING", int a = 0){
        set_name(n);
        set_ability(a);
    }

    /// @brief Set Player Name
    /// @param n (string) new name value
    void set_name(string n){
        _name = n;
    }

    /// @brief Set Player Score
    /// @param s (int) new score value to be set
    void set_score(int s){
        _score = s;
    }

    /// @brief Set Ability Level
    /// @param a (int) new ability level; Expected value: 0, 1, 2
    void set_ability(int a){
        _ability = a;
    }

    /// @brief Set Captain Status
    /// @param stat (int) denotes player vs captain; Expected value: 0, 1
    void set_status(int stat){
        _status = stat;
    }

    /// @brief Get Player Name
    /// @return (string) Name of current player
    string get_name(){
        return _name;
    }

    /// @brief Get Score
    /// @return (int) Score of current player; Expected Value >= 0
    int get_score(){

        // Error handling to ensure score isn't bugged
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
        catch (int s) {
            cout << "ERROR: Score is less than 0" << endl;
            cout << "Score: " << s << endl;
            exit(EXIT_FAILURE);
        }
    }
    
    /// @brief Get Ability
    /// @return (int) Ability level of current player; Expected Value: 0, 1, 2
    int get_ability(){

        // Error handling to ensure ability isn't bugged
        try{
            int a = _ability;
            if (a >= 0 && a <= 2) {
                return _ability;
            }
            else {

                // Throws error if ability level is less than 0 or greater than 2
                throw (a);
            }
        }
        catch (int a) {
            cout << "ERROR: Ability must be set to integer value 0 - 2" << endl;
            cout << "Ability: " << a << endl;
            exit(EXIT_FAILURE);
        }
    }

    /// @brief Get Captain Status
    /// @return (int) Captain Status of current player; Expected Value: 0, 1
    int get_status(){

        // Error handling to ensure captain status isn't bugged
        try{
            int s = _status;
            if (s == 0 || s== 1) {
                return _status;
            }
            else {

                // Throws error if status is  not 0 or 1
                throw(s);
            }
        }
        catch (int s) {
            cout << "ERROR: Invalid Status - Must be 0 for normal or 1 for captian" << endl;
            cout << "Status: " << s << endl;
            exit(EXIT_FAILURE);
        }
    }

    /// @brief Resets score to (int) 0 by invoking Score Setter
    void reset_score(){
        set_score(0);
    }

    /// @brief Play 1 turn if player; Play 2 turns if Captain
    void play_turn(){
        for (int i = 0; i <= get_status(); i++){
            int current_score = get_score();
            current_score += generate_score(get_ability());
            set_score(current_score);
        }
    }

    /// @brief Display player name and current score
    void display() {
        cout << get_name() << ": " << get_score() << endl;
    }
        
};

#endif