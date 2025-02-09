// Default copy constructor do shallow copy
// Shallow Copy: accessing same memory with two names
//   Deep Copy: second copy get created

#include <iostream>
#include <cstring>
using namespace std;


class Hero{
    
    public:
    int health;
    char level;
    char* name;
    
    Hero(){
        cout<<"Default Constructor called"<<endl;
        name = new char[100];
    }
    
    Hero(int health, char level, char name[]){                    //parameterized constructor
        this -> health = health;
        this -> level = level;
        //strcpy(this->name, name);
        this->name = name;
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
    
    void setHealth(int health) {
        this->health = health;
    }

    void setLevel(char level) {
        this->level = level;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }
    
    
    //  Hero(int health){               to use this type of constructor, default constructor is required to call
        
    // }
    
    private:
    int value;

};

int main(){

    char name[7] = "Babbar";
    
    Hero hero1(12,'D',name);            //static object

    // hero1.setHealth(12);
    // hero1.setLevel('D');
    // hero1.setName(name);

    hero1.print();

    //use default copy constructor

    Hero hero2(hero1);
    //  or Hero hero2 = hero1;
    
    hero2.print();

    hero1.name[0] = 'G';   //changing name of hero1 but name hero2 also get changed
    hero1.print();

    hero2.print();
    

    hero1 = hero2;   //all object of hero2 copied to hero1    hero1.health = hero2.health
    hero1.print();
    hero2.print();
    
    return 0;
}
