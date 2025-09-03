//           "Those who forget the past are condemned to repeat it." ~ George Santayana


// We can find bigger problem's optimal solution by using optimal solutions of its subproblems. 

// Dynamic Programming: An optimization over plain recursion. It is used when the problem can be broken down 
// into overlapping sub-problems which can be solved independently. The idea is to store the results of sub-problems 
// so that they do not have to be recomputed when needed later.

// Problems that can be solved using Dynamic Programming have two main properties:
// 1. Optimal Substructure: A problem exhibits optimal substructure if an optimal solution to the problem can be
//    constructed efficiently from optimal solutions of its sub-problems.
// 2. Overlapping Subproblems: A problem has overlapping subproblems if the problem can be broken down into 
//    subproblems which are reused several times.

// Approaches to implement Dynamic Programming:

// 1. Top-Down Approach (Memoization): In this approach, we start solving the problem from the top (the original problem)
//    and break it down into smaller subproblems. We store the results of these subproblems in a data structure (like
//    an array or a hash map) so that when we encounter the same subproblem again, we can simply look up the result
//    instead of recomputing it. This approach is often implemented using recursion with an additional data structure
//    to store the results of subproblems.

// 2. Bottom-Up Approach (Tabulation): In this approach, we solve the problem by first solving all the smaller subproblems
//    and then combining their results to solve larger subproblems until we reach the original problem. This approach is
//    typically implemented using iteration and a table (usually an array) to store the results of subproblems.

//  Fibonaci Series fun calls
//                                                f(6)
//                                             /       \ 
//                                         f(5)    +    f(4)
//                                       /    \            \ 
//                                   f(4)  +  f(3)  
//                                  /   \      
//                               f(3) + f(2) 
//                              /   \     
//                           f(2) + f(1) 
//                          /   \
//                       f(1) + f(0)
// 
//  As we can see, there are many Overlapping Subproblems. For example, f(4) is computed multiple times. 
//  By storing the results of these subproblems, we can avoid redundant calculations and improve efficiency.
//  And storing the results of subProbles is called Memorization.



class Solution {              // nth term of fibonacci

    int solve(int n, vector<int>& dp){

      if(dp[n] != -1){
        return dp[n];
      }
      
      // base case
      if(n <= 1) return n;

      dp[n] = solve(n-1, dp) + solve(n-2, dp);
      return dp[n];
    }

public:
    int fib(int n) {

        // DP TopDown: Recursion + Memorization   TC:O(n) SC:O(2n)
        vector<int> dp(n+1, -1);
        return solve(n, dp);

        // DP BottomUp : Tabulation               TC:O(n) SC:O(n)
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];

        // Space Optimization                    TC:O(n) SC:O(1)
        vector<int> dp(3, -1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
          dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];
        }
        return dp[n % 3];

    }
};

