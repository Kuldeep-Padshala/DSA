// LC: 2435 m 

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        // dp[i][j][r] = number of ways to reach (i,j) with sum%k == r
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];

                if (i == 0 && j == 0) continue;

                for (int r = 0; r < k; r++) {
                    int newR = (r + val) % k;

                    if (i > 0) {
                        dp[i][j][newR] = (dp[i][j][newR] + dp[i-1][j][r]) % MOD;
                    }
                    if (j > 0) {
                        dp[i][j][newR] = (dp[i][j][newR] + dp[i][j-1][r]) % MOD;
                    }
                }

            }
        }

        return dp[m-1][n-1][0];
    }
};