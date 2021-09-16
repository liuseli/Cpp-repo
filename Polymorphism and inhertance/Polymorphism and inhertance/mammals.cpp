// A Simple Program to practice multilevel inheritance and inheritance of protected member variables
// Base: Mammal -> Monkey -> Human

#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;

class Mammal{
public: 
    Mammal(void){
//        cout << "Mammal Constructed..." << endl;
    }
    ~Mammal(){
        cout << "Mammal destructed..." << endl;
    }

    virtual void move(){
        cout << "Mammals usually walk on 4 legs..." << endl;
    }
    virtual void speak(){
        cout << "Mammals make sounds..." << endl;
    }

};


class Monkey : public Mammal {
protected:
    int evolution_year ;
    int number_wrld ;
public:
    Monkey(void){
//        cout << "Monkey Constructed..." << endl;
        evolution_year = 1000;
        number_wrld = 200000;
    }
    ~Monkey(){
        cout << "Monkey destructed..." << endl;
    }
    void get_info(){
        cout << "The evolution of monkeys happened in: " << evolution_year << endl;
        cout << "The number of monkeys in the world is: " << number_wrld << endl;
    }
    void move(){
        cout << "A monkey walks on two legs..." << endl;
    }
    void speak(){
        cout << "Monkeys make sounds..." << endl;
    }

};

class Human : public Monkey{
protected:
    int evolution_year_hum;
    int number_wrld_hum;
public:
    Human(void){
//        cout << "Human Constructed..." << endl;
        evolution_year_hum = evolution_year+1000;
        number_wrld_hum = number_wrld+200000;
    }
    ~Human(){
        cout << "Human destructed..." << endl;
    }

    void get_info(){
        cout << "The evolution of monkeys happened in: " << evolution_year_hum << endl;
        cout << "The number of monkeys in the world is: " << number_wrld_hum << endl;
    }
    virtual void move(){
        cout << "A human walks on two legs..." << endl;
    }
    void speak(){
        cout << "Humans can speak..." << endl;
    }

};


int main(){
    Mammal *monkey = new Monkey;
    Mammal *human = new Human;

    cout << endl;
    cout << "Monkey and human constructed with pointers to Mammal object" << endl;
    monkey->move();
    monkey->speak();

    human->move();
    human->speak();
    cout<< endl << "Get_info() method cannot be used as there is no definition for this in Mammal class." <<endl;

    Monkey *monkey2 = new Monkey;
    Human *human2 = new Human;

    cout << endl;
    cout << "Money and human constructed with pointers to Mammal object" << endl;
    monkey2->move();
    monkey2->speak();
    monkey2->get_info();

    human2->move();
    human2->speak();
    human2->get_info();
    cout<< endl << "Get_info() method cannot be used as there is no definition for this in Mammal class." <<endl;

    delete monkey;
    delete human;




    return 0;
}