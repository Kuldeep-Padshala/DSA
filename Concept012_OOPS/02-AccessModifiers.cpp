// Access modifiers
// public
// private(default)
// protected

#include <iostream>
using namespace std;


class Hero{
    
    public:            //access anywhere
    int health;
    char level;
    
    private:
    int value;   //access only within class
    
    
};

int main(){
    
        Hero ramesh;
        
        ramesh.health = 70;
        ramesh.level = 'A';
        
    cout<<"Health is: "<< ramesh.health <<endl;
    cout<<"Level is: "<< ramesh.level <<endl;
    //cout<<"Value is: "<<ramesh.value<<endl;             //Error will occur

    return 0;
}