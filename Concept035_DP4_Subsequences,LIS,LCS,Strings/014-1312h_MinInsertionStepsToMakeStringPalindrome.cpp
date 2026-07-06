// LC: 1312 h 

class Solution {

      // LC: 1143 LCS
      int spaceOpt(const string& s1, const string& s2){

        int n = s1.length();
        int m = s2.length();
        
        vector<int> prev(m+1, 0);

        for(int idx1=1; idx1<=n; idx1++){
          
          vector<int> curr(m+1, 0);
          for(int idx2=1; idx2<=m; idx2++){

            if(s1[idx1-1] == s2[idx2-1]){
              curr[idx2] = 1 + prev[idx2-1];
            }
            else{
              int case1 = prev[idx2];
              int case2 = curr[idx2-1];
              curr[idx2] = max(case1, case2);
            }
          }
          prev = curr;
        }
        return prev[m];
      }

public:
    int minInsertions(string s) {
        
        string s2 = s;
        reverse(s.begin(), s.end());
        return s.size() - (spaceOpt(s, s2));
    }
};