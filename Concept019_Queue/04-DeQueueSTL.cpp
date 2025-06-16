// Input restricted queue: pushback, popfront, popback allewed
// output restricted queue: pushfront, pushback, popfront allowed
// Double ended queue: pushfront, pushback, popfront, popback allowed

#include <iostream>
#include <deque>
using namespace std;

int main() {
    
    deque<int> d;

    d.push_front(10);                // front ma add, front left side
    d.push_back(20);                 // back ma add, rear right side


    cout << d.front() << endl; // 10
    cout << d.back()  << endl;  // 20

    d.pop_front();                 // removes 10, front right side

    cout << d.front() << endl; // 20
    cout << d.back()  << endl;  // 20

    d.pop_back();                 // removes 20 , rear left side   
     
    if(d.empty()) {
        cout << "Deque is empty" << endl; // Deque is empty
    } else {
        cout << "Deque is not empty" << endl;
    }


    return 0;
}