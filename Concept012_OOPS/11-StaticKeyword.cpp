// static keyword creates a data member belongs to a class and does not need any object to access.

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
    static int timeToComplete;   //for static variable, we dont need object to access
    
    Hero(){
        cout<<"Default Constructor called"<<endl;
        name = new char[100];
    }
    
        Hero(int health, char level,int timeToComplete){
        this -> health = health;
        this -> level = level;
        this -> timeToComplete = timeToComplete;
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

int Hero::timeToComplete = 5;

int main(){
    
    cout<< Hero::timeToComplete <<endl;   // this statement will print 5
    
    Hero a;
    a.timeToComplete = 15 ;
    cout<<a.timeToComplete<<endl;
    cout<< Hero::timeToComplete <<endl;
    
    Hero b;
    b.timeToComplete = 10 ;
    cout  << a.timeToComplete << endl;
    cout << b.timeToComplete << endl;

    Hero c(100, 'A',20);
    cout<< "for c: "<<c.timeToComplete<<endl;
    
    return 0;
}
