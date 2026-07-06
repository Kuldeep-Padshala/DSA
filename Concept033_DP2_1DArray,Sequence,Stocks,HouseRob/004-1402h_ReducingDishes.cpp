// LC:1402 h 

class Solution {

      int recur(int idx, int time, vector<int>& satisfaction){

        // Base case
        if(idx == satisfaction.size()){
          return 0;
        }

        int include = satisfaction[idx] * (time+1)  + recur(idx+1, time+1, satisfaction);
        int exclude = recur(idx+1, time, satisfaction);

        return max(include, exclude);

      }

      int recurMemo(int idx, int time, vector<int>& satisfaction, vector<vector<int>>& dp){

        // Base case
        if(idx == satisfaction.size()){
          return 0;
        }

        // Check dp
        if(dp[idx][time] != -1){
          return dp[idx][time];
        }

        int include = satisfaction[idx] * (time+1)  + recurMemo(idx+1, time+1, satisfaction, dp);
        int exclude = recurMemo(idx+1, time, satisfaction, dp);

        return dp[idx][time] = max(include, exclude);
      }

      int tabulation(vector<int>& satisfaction){

        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int idx=n-1; idx>=0; idx--){
          for(int time=idx; time>=0; time--){

            int include = satisfaction[idx] * (time+1)  + dp[idx+1][time+1];
            int exclude = dp[idx+1][time];

            dp[idx][time] = max(include, exclude);
          }
        }
        return dp[0][0];
      }

      int spaceOpt(vector<int>& satisfaction){

        int n = satisfaction.size();
        vector<int> next(n+1, 0);

        for(int idx=n-1; idx>=0; idx--){

          vector<int> curr(n+1, 0);

          for(int time=idx; time>=0; time--){

            int include = satisfaction[idx] * (time+1)  + next[time+1];
            int exclude = next[time];

            curr[time] = max(include, exclude);
          }
          next = curr;
        }

        return next[0];
      }

      int spaceOpt2(vector<int>& satisfaction){

        int n = satisfaction.size();
        int ans = 0;                  // final max score
        int currSum = 0;

        // traverse from the end
        for(int i=n-1; i>=0; i--){
          
          currSum += satisfaction[i];
          if (currSum + ans > ans) {
            ans += currSum;
          } 
          else {
            break;  // no need to include anymore
          }
        }
        return ans;
      }

public:

    int maxSatisfaction(vector<int>& satisfaction) {
        
        // based on 01 knapsack, "include" dishes, "exclude" dishes
        // int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        // Recursion
        // return recur(0, 0, satisfaction);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return recurMemo(0, 0, satisfaction, dp);

        // BottomUp
        // return tabulation(satisfaction);

        // Space Optimization  O(n)
        // return spaceOpt(satisfaction);

        // Space Optimization 2, using greedy O(1)
        return spaceOpt2(satisfaction);
    }
};