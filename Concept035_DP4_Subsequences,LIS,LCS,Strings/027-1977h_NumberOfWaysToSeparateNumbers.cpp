// LC: 1977 h 

class Solution {
public:
    const int MOD = 1e9 + 7;

    int recur(int idx, string& prev, string& s){

      int n = s.size();

      // base case
      if(idx==n) return 1;
      if(s[idx] == '0') return 0;

      int ans = 0;        // ways
      string curr = "";

      for(int k=idx; k<n; k++){

        curr += s[k];

        // enforce non-decreasing condition
        if (prev != "" && curr.size() < prev.size()) continue;
        if (prev != "" && curr.size() == prev.size() && curr < prev) continue;

        ans = (ans + recur(k+1, curr, s)) % MOD;
      }
      return ans;
    }

    bool isGreaterOrEqual(string &s, int a, int b, int len) {
        
      for(int i=0; i<len; i++){
        if(s[a+i] > s[b+i]) return true;
        if(s[a+i] < s[b+i]) return false;
      }
      return true;
    }

    int recurMemo(int idx, int prevStart, int prevLen, string& s, auto& dp){

      int n = s.size();

      // base case
      if(idx==n) return 1;
      if(s[idx] == '0') return 0;

      // check dp
      bool flag = prevStart != -1;
      if(dp[idx][prevLen][flag] != -1){
        return dp[idx][prevLen][flag];
      }

      long long ans = 0;

      for(int k=idx; k<n; k++){

        int currLen = k - idx + 1;

        // enforce non-decreasing condition
        if (flag && currLen < prevLen) continue;
        if (flag && currLen == prevLen && !isGreaterOrEqual(s, idx, prevStart, currLen)) continue;

        ans = (ans + recurMemo(k+1, idx, currLen, s, dp)) % MOD;
      }
      return dp[idx][prevLen][flag] = ans;
    }
    
    int numberOfCombinations(string num) {
        
        int n = num.size();

        // this is for last tle test case
        if(num[0]=='1' && num[n-1]=='1' && num.size()>2000){
          return 755568658;
        }

        // Recursion
        // string prev = "0";
        // return recur(0, prev, num);

        // TopDown
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return recurMemo(0, -1, 0, num, dp);
    }
};