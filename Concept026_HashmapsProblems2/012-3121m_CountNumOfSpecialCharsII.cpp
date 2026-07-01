// LC: 3121 m 

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        int n = word.length();
        unordered_map<char, int> st, ans;

        for(int i=0; i<n; i++){
          char ch = word[i];

          if(ch>='a' && ch<='z'){
            st[ch] = i;
            
            // Fix 1: If uppercase was already seen (it is in ans), disqualify it with -1
            if(ans.find(ch) != ans.end()){
                ans[ch] = -1; 
            }
          }
          else if(ch >= 'A' && ch <= 'Z'){
            ch = tolower(ch);
            
            // Fix 2: Always record the FIRST occurrence of the uppercase, even if st is empty
            if(ans.find(ch) == ans.end()){
              ans[ch] = i;
            }
          }
        }

        int count = 0;
        // A character is special if it exists in BOTH maps AND wasn't disqualified
        for(auto it : st){
            char ch = it.first;
            if(ans.find(ch) != ans.end() && ans[ch] != -1){
                count++;
            }
        }

        return count;
    }
};