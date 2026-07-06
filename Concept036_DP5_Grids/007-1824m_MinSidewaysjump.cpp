// LC: 1824 m 

class Solution {
  
      int recur(int lane, int pos, vector<int>& obs){

        int n = obs.size();
        // Base case
        if(pos == n-1){
          return 0;
        }

        if(obs[pos+1] != lane){      // jo obstacle agad no hoi to
          return recur(lane, pos+1, obs);
        }
        else{                        // sideways jump 

          int ans = INT_MAX;
          for(int i=1; i<=3; i++){
            // no obstacle          curr lane no hovi joi
            if( (obs[pos] != i) && (i != lane) ){
              ans = min(ans, 1 + recur(i, pos, obs));
            }
          }
          return ans;
        }

      }

      int recurMemo(int lane, int pos, vector<int>& obs, vector<vector<int>>& dp){

        int n = obs.size();
        // Base case
        if(pos == n-1){
          return 0;
        }

        if(dp[lane][pos] != -1){
          return dp[lane][pos];
        }

        if(obs[pos+1] != lane){      // jo obstacle agad no hoi to
          return dp[lane][pos] = recurMemo(lane, pos+1, obs, dp);
        }
        else{                        // sideways jump 

          int ans = INT_MAX;
          for(int i=1; i<=3; i++){
            // no obstacle          curr lane no hovi joi
            if( (obs[pos] != i) && (i != lane) ){
              ans = min(ans, 1 + recurMemo(i, pos, obs, dp));
            }
          }
          return dp[lane][pos] = ans;
        }

      }

      int tabulation(vector<int>& obs){
        
        int n = obs.size();
        vector<vector<int>> dp(4, vector<int>(n, 1e9));

        // aya dp[i][j] shows minimum num of sideways jump to reach destination from j=n

        // Base case
        dp[0][n-1] = 0;
        dp[1][n-1] = 0;
        dp[2][n-1] = 0;
        dp[3][n-1] = 0;

        for(int pos=n-2; pos>=0; pos--){
          for(int lane=1; lane<=3; lane++){

            if(obs[pos+1] != lane){              // jo obstacle agad no hoi to
              dp[lane][pos] = dp[lane][pos+1];
            }
            else{                                // sideways jump   
              int ans = 1e9;
              for(int i=1; i<=3; i++){
                // no obstacle       curr lane no hovi joi
                if( (obs[pos] != i) && (i != lane) ){
                  ans = min(ans, 1 + dp[i][pos+1]);
                }
              }
              dp[lane][pos] = ans;
            }

          }
        }

        return min(dp[2][0], min((dp[1][0]+1), (dp[3][0]+1)));
      }

      int spaceOpt(vector<int>& obs){
        
        int n = obs.size();
        vector<int> curr(4, 1e9);
        vector<int> next(4, 1e9);

        // aya dp[i][j] shows minimum num of sideways jump to reach destination from j=n

        // Base case
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int pos=n-2; pos>=0; pos--){
          for(int lane=1; lane<=3; lane++){

            if(obs[pos+1] != lane){              // jo obstacle agad no hoi to
              curr[lane] = next[lane];
            }
            else{                                // sideways jump   
              int ans = 1e9;
              for(int i=1; i<=3; i++){
                // no obstacle       curr lane no hovi joi
                if( (obs[pos] != i) && (i != lane) ){
                  ans = min(ans, 1 + next[i]);
                }
              }
              curr[lane] = ans;
            }

          }
          next = curr;
        }

        return min(curr[2], min((curr[1]+1), (curr[3]+1)));
      }

public:
    int minSideJumps(vector<int>& obstacles) {

        // can also be done using Dijkstra with dequeueas shortest path must have minimum side jumps
        
        int n = obstacles.size();

        // Recursion
        // return recur(2, 0, obstacles);

        // TopDown
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return recurMemo(2, 0, obstacles, dp);

        // BottomUp
        // return tabulation(obstacles);

        // Space Optimization
        // return spaceOpt(obstacles);

    }
};