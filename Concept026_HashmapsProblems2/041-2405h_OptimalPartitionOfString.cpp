// LC: 2405 h 

class Solution {
public:
    int partitionString(string s) {

        int n = s.size();
        int count = 1;
        unordered_map<char, bool> mp;

        for(char ch: s){

          if(mp.find(ch) != mp.end()){
            count++;
            mp.clear();
          }
          mp[ch] = true;
        }
        return count;
        
        // bits
        // int mask = 0;
        // int parts = 1;

        // for(char c : s){
          
        //   int bit = 1 << (c - 'a');
        //   if (mask & bit) {
        //     parts++;
        //     mask = 0;
        //   }
        //   mask |= bit;
        // }

        // return parts;
    }
};