// Getters and setter are used to access the private variable
// they are normal functions

#include <iostream>
using namespace std;


class Hero{
    
    private:
    int value;          //access only within class
    
    public:            //access anywhere
    int health;
    char level;
    
    int getvalue(){              //this functions must be in public type
        return value;
    }
    void setvalue(int x){
        value = x;
    }
    void sethealth(int x){
        health = x;
    }
    
    
};

int main(){
    
        Hero ramesh;
        cout<<"Value is "<< ramesh.getvalue()<<endl;
        
        ramesh.setvalue(50);
        cout<<"Value is "<< ramesh.getvalue()<<endl;
        ramesh.sethealth(100);
        cout<<"Health is: "<< ramesh.health <<endl;
        
        
        // ramesh.value = 'A';
    //cout<<"Health is: "<<ramesh.value<<endl;    //Error will occur

    return 0;
}