// LC: 290 e 

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        map<char, string> mp1;
        map<string, char> mp2;

        int i1 = 0;
        int i2 = 0;
        int n = pattern.size();
        int m = s.size();

        while(i1 < n && i2 < m) {
            
          string temp = "";

          while(i2 < m && s[i2] == ' ') i2++;

          while (i2 < m && s[i2] != ' ') {
            temp += s[i2];
            i2++;
          }

          if(mp1.count(pattern[i1])) {
            if(mp1[pattern[i1]] != temp){
              return 0;
            }
          } 
          else {
            mp1[pattern[i1]] = temp;
          }

          if(mp2.count(temp)){
            if(mp2[temp] != pattern[i1]){
              return 0;
            }
          } 
          else {
            mp2[temp] = pattern[i1];
          }

          i1++;
        }
        if ((i1 == n && i2 != m) || (i1 != n && i2 == m))
            return 0;
        return 1;
    }
};