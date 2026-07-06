// LCC: 1547 h 

// partition dp

class Solution {

      int recur(int s, int e, vector<int>& cuts) {

        // Base case
        if(e-s <= 1){
          return 0;
        }  

        int ans = INT_MAX;

        // try every cut possible in range
        for(int cut=s+1; cut<e; cut++) {

          int costLeft = recur(s, cut, cuts);
          int costRight = recur(cut, e, cuts);

          int cost = (cuts[e] - cuts[s]) + costLeft + costRight;
          ans = min(ans, cost);
        }

        return ans;
      }

      int recurMemo(int s, int e, vector<int>& cuts, vector<vector<int>>& dp) {

        // Base case
        if(e-s <= 1){
          return 0;
        }

        // check dp
        if(dp[s][e] !=-1){
          return dp[s][e];
        }

        int ans = INT_MAX;

        // try every cut possible in range
        for(int cut=s+1; cut<e; cut++) {

          int costLeft = recurMemo(s, cut, cuts, dp);
          int costRight = recurMemo(cut, e, cuts, dp);

          int cost = (cuts[e] - cuts[s]) + costLeft + costRight;
          ans = min(ans, cost);
        }

        return dp[s][e] = ans;
      }

      int tabulation(int n, vector<int>& cuts){
        
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        // base case
        // for (int i=0; i<m; i++) {
        //   dp[i][i] = 0;
        //   if (i+1 < m) dp[i][i+1] = 0;
        // }

        for (int s = m-1; s >= 0; s--) {
          for (int e = s+1; e<m; e++) {

            // BASE CASE
            if(e-s <= 1){
              dp[s][e] = 0;
              continue;
            }
            int best = INT_MAX;

            // try every cut between s and r
            for (int cut = s + 1; cut < e; cut++) {
              int cost = (cuts[e] - cuts[s]) + dp[s][cut] + dp[cut][e];
              best = min(best, cost);
            }

            dp[s][e] = best;
          }
        }
        return dp[0][m-1];
      }
      
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        int m = cuts.size();

        // Recursion
        // return recur(0, m - 1, cuts);

        // TopDown
        // vector<vector<int>> dp(m, vector<int>(m, -1));
        // return recurMemo(0, m - 1, cuts, dp);

        // BottomUp
        return tabulation(n, cuts);

    }
};