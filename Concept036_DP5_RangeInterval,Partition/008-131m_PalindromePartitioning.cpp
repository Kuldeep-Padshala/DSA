// LC: 131 m 

class Solution {

      bool isPalindrome(int l, int r, string &s){

          while(l<r){

            if(s[l] != s[r]){
              return false;
              break;
            }
            l++; r--;
          }
          return true;
      }

      void recur(int idx, string &s, vector<string> &path,vector<vector<string>> &ans){

        // Base case: whole string consumed
        if (idx == s.size()) {
          ans.push_back(path);
          return;
        }

        // Partition from idx to end
        for (int end = idx; end < s.size(); end++) {

          if(isPalindrome(idx, end, s)){
            
            path.push_back(s.substr(idx, end - idx + 1));
            recur(end + 1, s, path, ans);
            path.pop_back(); // backtrack
          }
        }
      }

      vector<vector<string>> recurMemo(int idx, string &s, vector<vector<vector<string>>> &dp){
        
        int n = s.size();

        // Base case
        if(idx == n){
          return {{}};
        }

        // check dp
        if(!dp[idx].empty()){
          return dp[idx];
        }

        vector<vector<string>> res;

        // Try all partitions starting at idx
        for(int end = idx; end < n; end++) {

            // Palindrome check s[idx..end]

            if(isPalindrome(idx, end, s)){
              
              string curr = s.substr(idx, end - idx + 1);

              // Recurse on remaining suffix
              vector<vector<string>> next = recurMemo(end + 1, s, dp);

              for (auto &vec : next) {
                vector<string> temp;
                temp.push_back(curr);
                temp.insert(temp.end(), vec.begin(), vec.end());
                res.push_back(temp);
              }
            }
        }

        return dp[idx] = res;
      }
public:
    vector<vector<string>> partition(string s) {
        

        int n = s.size();

        // Recursion
        // vector<vector<string>> ans;
        // vector<string> path;
        // recur(0, s, path, ans);
        // return ans;

        // TopDown
        vector<vector<vector<string>>> dp(n);
        return recurMemo(0, s, dp);
    }
};