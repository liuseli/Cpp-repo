#include "playerclass.h"

using namespace std;

Player::Player(string name_n){
        name = name_n;
        health = 100;
        stamina = 50; 
        strength = 50;
        losses = 0;
        wins = 0;
        consecutive_wins = 0;
        cout << endl<< "A new fighter called " << name << " created!" << endl;
}

string Player::get_name(){
    return name;
}

void Player::get_details(){
    cout << "********************"<< endl;
    cout << "Player details" << endl << endl;
    cout << "Name: " << name << endl;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Consecutive wins: " << consecutive_wins << endl;
}

void Player::heal_player(){
    health = 100;
}
