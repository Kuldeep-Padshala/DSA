// static function does not need any object to access.
// 'this' keyword is not there
// static function can only access static data members
// non static function can access static data members

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
    static int timeToComplete;
    
    // Hero(){
    //     cout<<"Default Constructor called"<<endl;
    //     name = new char[100];
    // }
    
    static int random() {
        return timeToComplete ;
    }
    
    
};

int Hero::timeToComplete = 5;

int main(){
    
    cout<<Hero::random()<<endl;
    
    return 0;
}
