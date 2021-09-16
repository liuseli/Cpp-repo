// Rocky game is a small project to practice how to create header files and include them to the main program.
// Writing classes and their functions to separate header and cpp-files makes the code easier to handle and understand.
// Unfortunately commenting is done poorly. I to improve it lates.

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
#include <cstdlib>

#include "clearscreen.h"
#include "printinst.h"
#include "playerclass.h"
#include "rungame.h"


using namespace std;



int main(){
    string name;
    ClearScreen();
    //cout << endl << endl;
    cout << "********** Rocky Boxing Challenge 1.0 ***********"<< endl;
    cout << "Train your boxing character, win the matched and become a legend" << endl << endl;

    int user_in = 0;        // Variable for user input
    do{                     //Infinite loop to display the main menu unit user chooses what to do or wants to exit
        
        // Main menu outputs
        cout << "Input the number of wanted action and press enter:" << endl;
        cout << "1. Game instructions." << endl;
        cout << "2. New Game." << endl;
        cout << "3. Load Game." << endl << endl;

        cout << "Your selection:   ";
        cin >> user_in;      // Get the user input

        switch (user_in)        //Swith statements of the user inputs
        {
        case 1:{
            ClearScreen();
            Print_inst();
            cout<< endl << "Press Enter"<<endl;
            break;
        }
        case 2:{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            ClearScreen();
            cout << "Input your fighter's name:" << endl;
            getline(cin, name);
            Player character(name);
            character.get_details();
            name = character.get_name();
            cout << name << endl;
            cout<< endl << "Press Enter"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //run_game(character);
            break;
        }
        default:{
            cout<<"Wrong input.";
            // Next lines clear and ignore wrong inputs from cin
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;     
            break;
        }
        }
        
    } while (1);


    return 0;
}



