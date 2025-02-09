#include<iostream>
#include<stack>
using namespace std;



int main () {
    string str = "Kuldeep";

    stack<char> s;

    for (int i = 0; i<str.length(); i++) {          //pushing whole string in stack
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";                                //new string to store reverse string

    while(!s.empty()) {
        char ch = s.top();
        ans += (ch);   //also can use    ans.push_back(ch);

        s.pop();
    }

    cout << "answer is: "<< ans << endl;

    return 0;
}