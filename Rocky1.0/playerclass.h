#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

#include <string>
#include<iostream>

class Player {
    private:
        int consecutive_wins;
    protected:
        std::string name;
        int health;
        int stamina;
        int strength;
        int wins;
        int losses;
    public:
        Player(std::string name_n = "a");
    
        void get_details();

        std::string get_name();

        void heal_player();

};

#endif