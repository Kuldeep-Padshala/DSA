// LC: 859 e 

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int n = s.size();
        int m = goal.size();
        if(m != n) return false;
        unordered_set<char> st;

        if(s == goal){

          for(char ch: s){
            if(st.find(ch) != st.end()){
              return true;
            }
            st.insert(ch);
          }
        }

        vector<int> diff;
        for(int i=0; i<n; i++){
          if(s[i] != goal[i]){
            diff.push_back(i);
          }
        } 

        return diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
    }
};