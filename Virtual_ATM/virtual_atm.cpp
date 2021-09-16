// A miniproject to practise the basics of c++ and data encapsulation inside a class.
// The user can create a bank account, deposit and withdraw money and see account data
// All the functions are member functions of the class Account

#include<iostream>
#include<string>
#include<limits>

using namespace std;

class Account {

    private:
        string name;
        long int accountno;
        int PINno;
        double balance;

    public:
        void create_account(void){
            name = set_name();
            accountno = set_accNo();
            PINno = set_PIN();
            balance = set_balance();
            cout << endl << "New account created successdully!" << endl << endl;
        }
        string set_name(void){
            string acc_name;
            cout << "Write your full name." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, acc_name);
            return acc_name;
        }
        long int set_accNo(void){
            long int acc_no=0;
            cout << "Type account number. (Any number)" << endl;
            cin >> acc_no;  
            return acc_no;          
        }
        int set_PIN(void){
            int pin = 0;
            cout << "Type PIN number (4 digits)." << endl;
            cin >> pin;
            return pin;
        }
        double set_balance(void){
            double bal = 0;
            cout << "Wanted amount of money to be deposited." << endl;
            cin >> bal;
            return bal;
        }

        bool login(){
            long int acc_in = 0;
            int PIN_in = 0;
            cout << "Input your account number" << endl ;
            cin >> acc_in;
            cout << "Input your PIN" << endl ;
            cin >> PIN_in;
            if(acc_in == get_accountNo() && PIN_in == get_PIN()){
                cout << "Logging succeeded." << endl;
                return true;
            }
            else{
                cout << "Logging failed." << endl;
                return false;
            }
        }

        long int get_accountNo(){
            return accountno;
        } 
        int get_PIN(){
            return PINno;
        }
        string get_name(){
            return name;
        }
        double get_balance(){
            return balance;
        }

        void withdraw_money(){
            double wd_amount = 0;
            cout<< endl<< "Enter the amount to be withdrawn: " << endl;
            cin >> wd_amount;
            balance = balance - wd_amount;
            cout << endl <<"Balance after withdraw is: " << get_balance() << endl;
        }

        void deposit_money(){
            double dep_amount = 0;
            cout<< endl<< "Enter the amount to be deposited: " << endl;
            cin >> dep_amount;
            balance = balance + dep_amount;
            cout << endl <<"Balance after deposition is: " << get_balance() << endl;
        }

};

int main(){
    Account user;
    int sel_v = 0;
    int no_account = 0;
    string acc_name;
    long int acc_no = 0;
    int acc_PIN = 0;
    double acc_bal = 0;

    while(1){
        cout << endl << "Welcome to virtual ATM! \nSelect what you would want to do by inputting the number of wanted action.\n";
        cout << "1. Create a new account" << endl << "2. Log in" << endl << "3. Exit\n" << endl;
        cin >> sel_v;


        switch(sel_v){
            
            case 1:
                if(no_account < 1){
                    user.create_account();
                    ++no_account;
                    
                }
                else{
                    cout<< endl <<"Number of maximum amount of accounts has exceeded." << endl;
                }
                break;
            
            case 2:
                if(user.login()){
                    int sel_log = 0;
                    bool while_control = true;
                    cout << "Welcome " << user.get_name() << endl;
                    while(while_control){
                        cout << "Input the number of wanter action:" << endl;
                        cout << "1. Check account information." << endl
                             << "2. Withdraw money." << endl
                             << "3. Deposit money." << endl
                             << "4. Log out." << endl << endl;
                        cin >> sel_log;
                        switch(sel_log){
                            case 1:
                                cout<<"Account information:" << endl;
                                cout << "Full name: " << user.get_name() << endl
                                     << "Account number: " << user.get_accountNo() << endl
                                     << "Account balance: " << user.get_balance() << endl << endl;
                                break;
                            case 2:
                                user.withdraw_money();
                                break;
                            case 3:
                                user.deposit_money();
                                break;
                            case 4:
                                while_control = false;
                                break;
                            default:
                                cout<<"Wrong input.";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                break;        
                        }                     
                    }
                }
                break;

            case 3:
                exit(1);
                break;
            default:
                cout<<"Wrong input.";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
    return 0;
}