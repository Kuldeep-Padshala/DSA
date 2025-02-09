#include <iostream>              //Defalult Constructor
using namespace std;


class Hero{

    private:
    int value;   //access only within class

    
    public:            //access anywhere
    int health;
    char level;
    
    Hero(){
        cout<<"Constructor called"<<endl;
    }
    Hero(int health, char level){
        this->health = health;
        this->level = level;
        
    }

};

int main(){
    
    cout<<"Hi"<<endl;
    Hero ramesh;   //while writing this a type of function or constructor hero called. ramesh.Hero() same for dynamic
    cout<<"Hello"<<endl;

    Hero *h = new Hero(120, 'A');
    cout<<"Health is: "<< h->health <<endl;
    cout<<"Level is: "<< h->level <<endl;
        
    return 0;
}