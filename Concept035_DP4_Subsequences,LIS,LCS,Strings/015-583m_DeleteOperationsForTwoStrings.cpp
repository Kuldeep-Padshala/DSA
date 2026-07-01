// LC: 583 m 

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
    int minDistance(string word1, string word2) {
        
        int L = spaceOpt(word1, word2);

        int Deletions = word1.size() - L;
        int Insertions = word2.size() - L;

        return Deletions + Insertions;

    }
};


// Exactly same answer for this too, though the concept is little different
// Minimum insertions or deletions to convert string A to B
// Subscribe to TUF+

// Given two strings word1 and word2, find the minimum number of insertions and deletions in string word1 required to transform word1 into word2.

// Insertion and deletion of characters can take place at any position in the string.