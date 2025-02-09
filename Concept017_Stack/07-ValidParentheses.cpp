#include<iostream>                     
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

     stack<char> sta;

     for(int i=0; i<s.length(); i++) {
         
         char ch = s[i];
         
         if(ch == '(' || ch == '{' || ch == '['){    //if open bracket,push
             sta.push(ch);
         }
         else                                        //if close bracket, stacktop check and pop
         {
             //for closing bracket
             if(!sta.empty()) {
                  char top = sta.top();
                  if( (ch==')' && top =='(') || ( ch=='}' && top =='{') || (ch==']' && top=='[') ) {
                      sta.pop();
                  }
                 else
                     return false;
             }
             else
                 return false;
         }  
     }
    
    if(sta.empty())
        return true;
    else
        return false;

    }
};