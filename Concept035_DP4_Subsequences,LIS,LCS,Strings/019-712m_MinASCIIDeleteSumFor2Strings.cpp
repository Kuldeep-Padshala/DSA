// LC: 712 m 

class Solution {

      // LC: 1143 LCS, with changes, this will return ASCII values, not length
      int spaceOpt(const string& s1, const string& s2){

        int n = s1.length();
        int m = s2.length();
        
        vector<int> prev(m+1, 0);

        for(int idx1=1; idx1<=n; idx1++){
          
          vector<int> curr(m+1, 0);
          for(int idx2=1; idx2<=m; idx2++){

            if(s1[idx1-1] == s2[idx2-1]){
              curr[idx2] = s1[idx1-1] + prev[idx2-1];
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
    int minimumDeleteSum(string s1, string s2) {
        
        int sum1 = 0, sum2 = 0;
        for(char c : s1) sum1 += c;
        for(char c : s2) sum2 += c;

        return sum1 + sum2 - 2*(spaceOpt(s1, s2));
    }
};