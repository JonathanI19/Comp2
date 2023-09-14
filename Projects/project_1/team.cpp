/*
team.cpp

@author Jonathan Isely
@contact tuf91237@temple.edu
@date 9/13/2023

Example:
    This file can be compiled by typing 
    make all

    This file can be run by typing
    ./play_game 2
*/

#ifndef _TEAM_
#define _TEAM_

#include "player.cpp"
#include <iostream>
#include <string>
#include <vector>

/// @brief Generates team object 
/// @param n (string) name of team to be passed into constructor
class team{

    private:
    
    /// @brief (player*) Vector of player objects
    vector <player*> _players;

    /// @brief (string) Name of team
    string _name = "";

    /// @brief Total score of team, not to be confused with _score variable located in individual player objects
    int _score = 0;

    public:

    // Constructor, accepts string
    team(string n = "NAME MISSING"){
        set_name(n);
    }

    /// @brief Set Team Name
    /// @param n (string) new team name value
    void set_name(string n) {
        _name = n;
    }

    /// @brief Set Team Score
    /// @param s (int) new team score value to be set
    void set_score(int s) {
        _score = s;
    }

    /// @brief Get Team Name
    /// @return (string) Name of current Team
    string get_name() {
        return _name;
    }

    /// @brief Get Team Score
    /// @return (int) Score of current team; Expected Value >= 0
    int get_score() {
        
        // Error handling to ensure total score isn't bugged
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

    /// @brief Add Player object to _players vector
    /// @param obj (player*) Player object
    /// @param status (int) Determines whether player will become team captain; Expected Value: 0 = Player, 1 = Captain
    void add_player(player* obj, int status) {

        // Overrides previous captain
        if (status == 1) {
            clear_captain();
            cout << "Captain of " << get_name() << " specifed as: " << obj->get_name() << endl;
        }
        _players.push_back(obj);
        obj->set_status(status);
    }

    /// @brief Clears captain data from all team members and sets them to regular players
    void clear_captain() {
        if (_players.size() > 0){
            for (int i = 0; i < _players.size(); i++){
                _players[i]->set_status(0);
            }
        }
    }

    /// @brief Plays a turn and tallies each players current total
    void play_turn() {

        // Checks to make sure team is populated
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

                // Throws error if team is empty
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