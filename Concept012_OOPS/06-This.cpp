#include <iostream>               //Parameterised Constructor
using namespace std;


class Hero{
    
    public:            //access anywhere
    int health;
    char level;
    
    Hero(){
        cout<<"Constructor called"<<endl;
    }
    
    Hero(int health){
        cout<<"this: "<<this<<endl;
        this -> health = health;             // 'this' is a pointer pointing current object(ramesh), store address
    }
    
    int getHealth(){
        return health;
    }
    
    private:
    int value;   //access only within class

};

int main(){
    
    Hero ramesh(10);
    cout<<"Address of ramesh: "<< &ramesh<<endl;
    ramesh.getHealth();
    
    Hero *h = new Hero();
    
    return 0;
}