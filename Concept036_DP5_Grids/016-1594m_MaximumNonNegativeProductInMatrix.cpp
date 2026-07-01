// LC: 1594 m 

class Solution {
public:

    const int MOD = 1e9+7;

    pair<long long, long long> recur(int i, int j, vector<vector<int>>& grid){

        // base case
        if(i==0 && j==0){
          return {grid[0][0], grid[0][0]};
        }

        long long curr = grid[i][j];

        long long maxProd = LLONG_MIN;
        long long minProd = LLONG_MAX;

        // move up
        if (i-1 >= 0) {
            
          auto up = recur(i-1, j, grid);

          long long a = curr * up.first;
          long long b = curr * up.second;

          maxProd = max(maxProd, max(a, b));
          minProd = min(minProd, min(a, b));
        }

        // move left
        if(j-1 >= 0){
          
          auto left = recur(i, j - 1, grid);

          long long a = curr * left.first;
          long long b = curr * left.second;

          maxProd = max(maxProd, max(a, b));
          minProd = min(minProd, min(a, b));
        }

        return {maxProd, minProd};
    }

    pair<long long, long long> recurMemo(int i, int j, vector<vector<int>>& grid, auto& dp) {

        // base case
        if(i == 0 && j == 0){
          return {grid[0][0], grid[0][0]};
        }

        // check dp
        if(dp[i][j].first != LLONG_MIN){
          return dp[i][j];
        }

        long long curr = grid[i][j];

        long long maxProd = LLONG_MIN;
        long long minProd = LLONG_MAX;

        // move up
        if (i-1 >= 0) {
          auto up = recurMemo(i-1, j, grid, dp);

          long long a = curr * up.first;
          long long b = curr * up.second;

          maxProd = max(maxProd, max(a, b));
          minProd = min(minProd, min(a, b));
        }

        // move left
        if(j-1 >= 0){
          auto left = recurMemo(i, j-1, grid, dp);

          long long a = curr * left.first;
          long long b = curr * left.second;

          maxProd = max(maxProd, max(a, b));
          minProd = min(minProd, min(a, b));
        }

        return dp[i][j] = {maxProd, minProd};
    }


    int maxProductPath(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        // Recursion
        // auto ans = recur(m-1, n-1, grid).first;
        // if(ans < 0) return -1;
        // else return ans % MOD;

        // TopDown
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n, {LLONG_MIN, LLONG_MIN}));
        auto ans = recurMemo(m-1, n-1, grid, dp).first;
        if(ans < 0) return -1;
        else return ans % MOD;
    }
};