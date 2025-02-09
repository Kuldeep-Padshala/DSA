// Destructor also created as the class is created 
// name same as the class
// no return type no input parameters
// ~tinda sign
// called once

#include <iostream>
#include <cstring>
using namespace std;


class Hero{
    
    private:
    int value;

    public:
    int health;
    char level;
    char* name;
    
    Hero(){
        cout<<"Default Constructor called"<<endl;
        name = new char[100];
    }
    
        Hero(int health, char level){
        this -> health = health;
        this -> level = level;
    }
        //own copy constructor                  for deep copy
    Hero(Hero& temp){                         // in copy constructor - pass by reference
                                              // once our copy constructor made , default one got ignored
        char* ch = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        
        cout<<"Copy Constructor called"<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }
    
    void print(){
        cout<<endl;
        cout<<"name: "<< this->name <<endl;
        cout<<"health: "<< this->health <<endl;
        cout<<"level: "<< this->level <<endl;
        
    }
    
    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }
    
    
    //  Hero(int health){               to use this type of constructor, default constructor is required to call
        
    // }
    
    ~Hero(){
        cout<<"Destructor called"<<endl;
    }
    
   
};

int main(){
    
    //static                here destructor called automatically
    Hero a;
    Hero c;
    
    //dynamic               here destructor called manually
    Hero *b = new Hero();
    Hero *d = new Hero();
    delete b;
    
    return 0;
}
