#include <iostream>              //Copy Constructor or Parameterized Constructor
using namespace std;


class Hero{
    
    public:
    int health;
    char level;
    
    Hero(){
        cout<<"Default Constructor called"<<endl;
    }
    
    Hero(int health, char level){                    //parameterized constructor
        this -> health = health;
        this -> level = level;
    }

    void print(){
        cout<<"health: "<< this->health <<endl;
        cout<<"level: "<< this->level <<endl;
    }
    
    
    //  Hero(int health){               to use this type of constructor, default constructor is required to call
        
    // }
    
    private:
    int value;

};

int main(){
    
    Hero suresh(70,'N');           //parameterized constructor
    suresh.print();
    
    Hero ritesh(suresh);                        //copy constructor
    // it means ritesh.health = suresh.health;
    //          ritesh.level = suresh.level
    ritesh.print();
    
    return 0;
}