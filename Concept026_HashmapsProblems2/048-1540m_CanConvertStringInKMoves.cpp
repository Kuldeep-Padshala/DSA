// LC: 1540 m 

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        
        int n = s.size();
        int m = t.size();

        if(n != m){
          return false;
        }

        vector<int> mp(26);
        for(int i=0; i<n; i++){

          mp[(t[i] - s[i] + 26) % 26]++;
        }

        for(int i=1; i<26; i++){
          if(mp[i] != 0 && (mp[i]-1)*26+i > k){
            return false;
          }
        }
        return true;
    }
};