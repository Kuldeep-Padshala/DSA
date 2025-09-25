// gfg

// Disarrangement of balls
// Difficulty: MediumAccuracy: 34.57%Submissions: 20K+Points: 4
// You are given n balls numbered from 1 to n and there are n baskets numbered from 1 to n in front of you. 
// The ith basket is meant for the ith ball. Calculate the number of ways in which no ball goes into its respective basket.

// Note: The answer will always fit into a 32-bit integer.

// User function Template for C++

class Solution {
    
    long long int solve(int n, vector<long long int>& dp){
        
        // Base case
        if(n==1) return 0;
        if(n==2) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        // so here, for example 0 at idx 0 is swapped with i, 
        //          whats remaining: n-2 num and n-2 blocks
        //  posibility 2: 0 is placed at index i, but i not placed at 0,
        //          whats remaining to solve n-1 and n-1
        //      n-1 is to place zero at index i
        //  so dp[n] = (n-1) * [f(n-1) + f(n-2)]
        dp[n] = (n-1) * (solve(n-1, dp) + solve(n-2, dp));
        return dp[n];
    }
  public:
    int countDer(int n) {
        
        // ------------------ TopDown: Recursion + Memoization ------------------
        // vector<long long int> dp(n+1, -1);
        // return solve(n, dp);
        
        // ------------------  BottomUp: Tabulation  ---------------------
        
        const int MOD = 1000000007; // usually modulus is required
        vector<long long int> dp(n+1, 0);

        // base cases
        if(n == 1) return 0;
        if(n == 2) return 1;

        dp[1] = 0;
        dp[2] = 1;
        // bottom-up fill
        for(int i = 3; i <= n; i++) {
            dp[i] = ( (i-1) * ( (dp[i-1] + dp[i-2]) % MOD ) ) % MOD;
        }

        return (int)dp[n];
        
    }
};