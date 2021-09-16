// In this simple exercise, I practise the basic consept of Inheritance and Polymorphism
// First, I create a base class called Shape after which I create three other classes - Circle, Square and Triangle
// These there classes are derived classes from the base class Shape.
// In base class, I define a pure virtual member function called draw. This function is overridden in derived classes.

#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;

class Shape {
    public:
        Shape(){}
        virtual ~Shape(){}
        // Pure virtual function called draw()
        virtual void draw() = 0;

};

//Create classes Circle, Square and Triangle by inheriting class Shape.
//Member function draw() will be overriden
class Circle : public Shape{
    public:
        Circle(){}
        ~Circle(){}
        void draw(){
            cout << "Drawing a Circle" <<endl;
        }

};

class Square : public Shape{
    public:
        Square(){}
        ~Square(){}
        void draw(){
            cout << "Drawing a Square"<<endl;
        }
    
};

class Triangle : public Shape{
    public:
        Triangle(){}
        ~Triangle(){}
        void draw(){
            cout << "Drawing a Triangle"<<endl;
        }

};


//For practice, let's make function which can use object method draw() as well. 
//The input argument is defined to be a reference to the shape class
void drawing(Shape &S);



int main(){

    //Construct an array of pointers containing all the derived classes
    //Method using a pointer array of pointers
    Shape **ptr_arr = new Shape*[3];

    ptr_arr[0] = new Circle();
    ptr_arr[1] = new Square();
    ptr_arr[2] = new Triangle();

    //ptr_arr[0]->draw();
    for(int i = 0; i < 3; ++i){
        ptr_arr[i]->draw();
    }

    for(int i = 0; i < 3; ++i){
        delete ptr_arr[i];
    }

    
    //Method using vector

    vector<Shape *> vect_arr;
    vect_arr.push_back(new Circle());
    vect_arr.push_back(new Square());
    vect_arr.push_back(new Triangle());
    cout<<endl;

    for(int i=0; i < 3; i++){
        vect_arr[i]->draw();
    }


    drawing(*ptr_arr[0]);
    

}

void drawing(Shape &S){
    S.draw();
}