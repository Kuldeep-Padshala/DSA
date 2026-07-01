// LC: 3120 m 

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_set<char> st, ans;

        for(char ch: word){

          if(ch>='a' && ch<='z'){
              st.insert(ch);
          }
        }

        for(char ch: word){

          if(ch<'a' && st.find(tolower(ch)) != st.end()){
            ans.insert(ch);
          }
        }

        return (int) ans.size();
    }
};