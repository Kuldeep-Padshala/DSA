// gfg

// Painting the Fence
// Given a fence with n posts and k colours, find out the number of ways of painting the fence so that 
// not more than two consecutive posts have the same colours.
// Answers are guaranteed to be fit into a 32 bit integer.

class Solution {
        
        int solve(int n, int k, vector<int>& dp){
            
            //Base case
            if(n==1) return k;

            // if there are two posts, then both can be same color or both can be different color
            if(n==2) return k + k*(k-1);
            
            if(dp[n] != -1){
                return dp[n];
            }
            // So here, we have two cases:
            // 1. Last two posts have same color: (n-2)th post should be different color than last two
            // adding 2 same color posts on n-2th post, and it should not be same color as n-2th post
            // so (k-1) choices
            // so each way of painting n-2 posts, we have (k-1) choices
            int last2Same = solve(n-2, k, dp) * (k-1);

            // 2. Last two posts have different color: (n-1)th post can be of any color except last one
            // adding one post with different color than (n-1)th post, so (k-1) choices
            // so each way of painting n-1 posts, we have (k-1) choices
            int last2Diff = solve(n-1, k, dp) * (k-1);
            
            dp[n] = last2Same + last2Diff;
            return dp[n];
        }
  public:
    int countWays(int n, int k) {
        // code here
        
        // ------------------ TopDown: Recursion + Memoization ------------------
        // vector<int> dp(n+1, -1);
        // return solve(n, k, dp);

        // ------------------  BottomUp: Tabulation  ---------------------
        // vector<int> dp(n+1, 0);

        // dp[1] = k;
        // if(n>1) 
        // dp[2] = k + k*(k-1);
        // for(int i=3; i <= n; i++) {
        //     dp[i] = (dp[i-1]*(k-1)) + (dp[i-2]*(k-1));
        // }
        // return dp[n];

        // ------------------ BottomUp Space Optimization  ---------------------
        if(n==1) return k;
        int prev2 = k;            // dp[i-2]
        int prev1 = k + k*(k-1);  // dp[i-1]

        for(int i=3; i <= n; i++) {
            int curr = (prev1*(k-1)) + (prev2*(k-1));
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;

    }
};