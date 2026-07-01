// LC: 205 e 

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        // int n = s.length();
        // unordered_map<char, int> mp1;
        // unordered_map<char, int> mp2;

        // for(int i=0; i<n; i++){
            
        //   if(mp1.find(s[i]) == mp1.end()) {
        //     mp1[s[i]] = i;
        //   }

        //   if(mp2.find(t[i]) == mp2.end()) {
        //     mp2[t[i]] = i;
        //   }

        //   if(mp1[s[i]] != mp2[t[i]]) {
        //     return false;
        //   }
        // }

        // return true; 

        int n = s.length();
        unordered_map<char, char> mp;

        for(int i=0; i<n; i++){
            
            char ch1 = s[i];
            char ch2 = t[i];

            if(mp.count(ch1)) {
              if (mp[ch1] != ch2) {
                  return false;
              }
            } 
            else {
              for(auto& pair : mp){
                if(pair.second == ch2){
                  return false;
                }
              }
              mp[ch1] = ch2;
            }
        }

        return true; 
    }
};