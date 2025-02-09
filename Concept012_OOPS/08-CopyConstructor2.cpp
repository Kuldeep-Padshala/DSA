#include <iostream>              //Copy Constructor
using namespace std;


class Hero{
    
    public:
    int health;
    char level;
    
    Hero(){
        cout<<"Default Constructor called"<<endl;
    }
    
    Hero(int health, char level){
        
        this -> health = health;
        this -> level = level;
    }
    
    //own copy constructor
    Hero(Hero& temp){                         // in copy constructor - pass by reference
        cout<<"Copy Constructor called"<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }   //dont need of this constructor, it is automatically created by compiler
    
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
    
    Hero ritesh(suresh);
    ritesh.print();
    
    return 0;
}