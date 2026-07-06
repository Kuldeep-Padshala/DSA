// gfg

// Maximize The Cut Segments
// Difficulty: MediumAccuracy: 24.29%Submissions: 254K+Points: 4
// Given an integer n denoting the Length of a line segment. You need to cut the line segment in such a way that 
// the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum. 
// Return the maximum number of cut segments possible.

// Note: if no segment can be cut then return 0.

class Solution {
        
        int solve(int n, int x, int y, int z, vector<int>& dp){
            
            // base case
            if(n==0) return 0;
            if(n<0) return INT_MIN;
            
            if(dp[n]!=-1){
                return dp[n];
            }
            
            int a = solve(n-x, x, y, z, dp) + 1;
            int b = solve(n-y, x, y, z, dp) + 1;
            int c = solve(n-z, x, y, z, dp) + 1;
            
            dp[n] =  max(a, max(b,c));
            return dp[n];
        }
  
  public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        // only one state is changing, so we need 1D dp
        
        // ------------------ TopDown: Recursion + Memoization ------------------
        vector<int> dp(n+1, -1);
        int ans = solve(n, x, y, z, dp);
        
        if(ans<0) return 0;
        else return ans;

        // ------------------  BottomUp: Tabulation  ---------------------
        // vector<int> dp(n+1, INT_MIN);
        // dp[0] = 0;
        
        // for(int i=1; i <= n; i++) {
        //     // if dp initialised with -1, then check one more condition dp[i-x] != -1
        //     if(i-x >= 0)
        //     dp[i] = max(dp[i], dp[i-x]+1);
            
        //     if(i-y >= 0)
        //     dp[i] = max(dp[i], dp[i-y]+1);
            
        //     if(i-z >= 0)
        //     dp[i] = max(dp[i], dp[i-z]+1);
        // }
        
        // if(dp[n]<0) return 0;
        // else return dp[n];

    }
};