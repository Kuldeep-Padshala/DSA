// LC: 1941 e 

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        
        int n = s.length();
        unordered_map<char, int> mp;

        for(char ch: s){

          if(mp.find(ch) == mp.end()) mp[ch] = 1;
          else mp[ch]++;
        }

        if(n % mp.size() != 0) return false;

        int temp = mp[s[0]];
        for(auto it = mp.begin(); it != mp.end(); it++){
          if(it->second != temp) return  false;
        }

        return true;
    }
};