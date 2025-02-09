#include <iostream>
//#include "Hero.cpp"         if the class is in other file
using namespace std;

class Hero{
    public:
    //properties
    int health;            //only declare here
    char level;
};


int main(){
    
    Hero ramesh;
    cout<<"Health is: "<< ramesh.health <<endl;    //Error will occur
    cout<<"Level is: "<< ramesh.level <<endl;
    
    cout<<"size: "<<sizeof(ramesh)<<endl;         //1 for empty class

    return 0;
}