// LC: 1897 e 

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        int n = words.size();
        
        if(words.size() == 1) {
          return true;
        }

        int letters = 0;
        for(const string& s: words){
          letters += s.length();
        }

        if(letters % n != 0) {
          return false;
        }

        vector<int> mp(26, 0);
        for(const string& s: words){
          for (char ch: s) {
            mp[ch-'a']++;
          }
        }

        for(int i: mp) {
          if (i % n != 0) {
            return false;
          }
        }

        return true;
    }
};