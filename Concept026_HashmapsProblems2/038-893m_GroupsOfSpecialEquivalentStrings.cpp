// LC: 893 m 

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        
        int n = words[0].size();
        unordered_set<string> st;

        for(string& word : words){
            
          string even, odd;

          for(int i=0; i<n; i++){
            if (i % 2 == 0) even += word[i];
            else odd += word[i];
          }

          sort(even.begin(), even.end());
          sort(odd.begin(), odd.end());
          st.insert(even + "#" + odd); // # separator
        }

        return st.size();
    }
};