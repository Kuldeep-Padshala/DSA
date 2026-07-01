// LC:1155 m 
// Distinct ways pattern

class Solution {

      int recur(int dice, int faces, int target){
        
        // Base case
        if(target<0){
          return 0;
        }
        if(dice==0 && target !=0){      // dices are over, but not reached target
          return 0;
        }
        if(target==0 && dice!=0){       // reached target but dices are not over, there's no zero face
          return 0;
        }
        if(target==0){
          return 1;
        }
        int ans = 0;
        for(int i=1; i<=faces; i++){
          ans = ans + recur(dice-1, faces, target-i);
        }
        return ans;

      }

      int recurMemo(int dice, int faces, int target, vector<vector<int>>& dp){
        
        // Base case
        if(target<0){
          return 0;
        }
        if(dice==0 && target !=0){      // dices are over, but not reached target
          return 0;
        }
        if(target==0 && dice!=0){       // reached target but dices are not over, there's no zero face
          return 0;
        }
        if(target==0){
          return 1;
        }

        // check dp
        if(dp[dice][target] != -1){
          return dp[dice][target];
        }

        long long ans = 0;
        for(int i=1; i<=faces; i++){
          ans = ans + recurMemo(dice-1, faces, target-i, dp);
        }
        ans %= 1000000007;
        return dp[dice][target] = ans;
      }

      int tabulation(int total_dice, int faces, int final_target){

        vector<vector<int>> dp(total_dice+1, vector<int>(final_target+1, 0));

        dp[0][0] = 1;

        for(int dice = 1; dice <= total_dice; dice++){
          for(int target = 1; target<=final_target; target++){
            
            long long ans = 0;
            for(int i=1; i<=faces; i++){
              if(target-i < 0) break;
              ans = ans + dp[dice-1][target-i];
            }
            ans %= 1000000007;
            dp[dice][target] = ans;
          }
        }

        return dp[total_dice][final_target];
      }

      int spaceOpt(int total_dice, int faces, int final_target){

        // vector<vector<int>> dp(total_dice+1, vector<int>(final_target+1, 0));
        vector<int> prev(final_target+1, 0);

        prev[0] = 1;

        for(int dice = 1; dice <= total_dice; dice++){

          vector<int> curr(final_target+1, 0);
          for(int target = 1; target<=final_target; target++){
            
            long long ans = 0;
            for(int i=1; i<=faces; i++){
              if(target-i < 0) break;
              ans = ans + prev[target-i];
            }
            ans %= 1000000007;
            curr[target] = ans;
          }
          prev = curr;
        }

        return prev[final_target];
      }
public:

    int numRollsToTarget(int n, int k, int target) {
        
        // Recursion
        // return recur(n, k, target);

        // TopDown
        // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        // return recurMemo(n, k, target, dp);

        // BottomUp
        // return tabulation(n, k, target);

        // space optimization
        return spaceOpt(n, k, target);
    }
};