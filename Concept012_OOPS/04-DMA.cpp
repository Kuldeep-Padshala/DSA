#include <iostream>
using namespace std;


class Hero{
    
    private:
    int value;   //access only within class
    
    public:            //access anywhere
    int health;
    char level;
    
    int getvalue(){              //this functions must be in public type
        return value;
    }

    void setvalue(int x){
        value = x;
    }
    
};

int main(){
    
    //Static
    Hero ramesh;
    ramesh.level='A';
    ramesh.setvalue(80);
    cout<<"Level is: "<<ramesh.level<<endl;
    cout<<"Value is "<< ramesh.getvalue()<<endl;
    
    //Dynamic
    Hero* h = new Hero();              // just like int* i = new int;  pointer h is pointing to a block created in heap
    (*h).level='B';
    (*h).setvalue(55);
    cout<<"Level is: "<<(*h).level<<endl;
    cout<<"Value is "<< (*h).getvalue()<<endl; 
    
    //Also written as 
    h->level='C';
    h->setvalue(14);
    cout<<"Level is: "<< h->level <<endl;
    cout<<"Value is "<< h->getvalue() <<endl;
    

    return 0;
}