// LC: 3146 e 

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        
        int n = s.length();
        int ans = 0;

        for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){
            if(s[i]==t[j]) ans += abs(i-j);
          }
        }
        return ans; 
        
        // int n = s.length();
        // unordered_map<char, int> mp;

        // int ans = 0;

        // for(int i=0; i<n; i++){
        //   mp[s[i]] = i;
        // }

        // for(int i=0; i<n; i++){
        //   ans += abs(mp[t[i]] - i);
        // }

        // return ans;
    }
};