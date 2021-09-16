#include"rungame.h"
#include"playerclass.h"
#include"clearscreen.h"

using namespace std;

void run_game(Player character){
    bool runner = true; //Boolean variable to keep the while-loop ongoin as long as user wants to
    int user_in = 0; // Variable to navigate in switch-loop
    string name_n = character.get_name();
    while(runner){   //Displays the game menu until user decides to stop playing
        ClearScreen();
        cout<< "********************";
        cout << "Welcome to new game, " << name_n << "!" << endl; // Welcomes the player and prints the name of the character
        cout << endl << "Select what you want to do" << endl;
        cout << endl << "1. Go climbing stairs and train stamina.";
        cout << endl << "2. Go to the gym and train strength.";
        cout << endl << "3. Go for the next fight." << endl;
        
        cout << "enter 1 for false:";
        cin >> user_in;
        if (user_in == 1){
            runner = false;
        }
    }

}