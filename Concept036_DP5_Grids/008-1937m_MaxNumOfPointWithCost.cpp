// LC: 1937 m 

class Solution {

      // Recursive (very slow, O(m * n^2))
      long long recur(int row, int col, vector<vector<int>>& pts) {
        
        // Base case
        if(row == 0){
          return pts[0][col];
        }

        long long maxi = LLONG_MIN;

        for (int prev=0; prev < pts[0].size(); prev++) {    // every cell na prev row na badhai cell check

          long long score = pts[row][col] + recur(row-1, prev, pts) - abs(col - prev);
          maxi = max(maxi, score);
        }
        return maxi;
      }

      long long recurMemo(int row, int col, vector<vector<int>>& pts, vector<vector<long long>>& dp) {
        
        // Base case
        if(row == 0){
          return dp[0][col] = pts[0][col];
        }

        if(dp[row][col] != -1){
          return dp[row][col];
        }

        long long maxi = LLONG_MIN;

        for (int prev=0; prev < pts[0].size(); prev++) {    // every cell na prev row na badhai cell check

          long long score = pts[row][col] + recurMemo(row-1, prev, pts, dp) - abs(col - prev);
          maxi = max(maxi, score);
        }
        return dp[row][col] = maxi;
      }

      long long tabulation(vector<vector<int>>& pts) {

        int m = pts.size(); 
        int n = pts[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        
        // Base case
        for (int col = 0; col < n; col++) {
          dp[0][col] = pts[0][col];
        }
        
        // Fill table
        for (int row = 1; row < m; row++) {
          for (int col = 0; col < n; col++) {

            long long maxi = LLONG_MIN;

            for (int prev = 0; prev < n; prev++) {
              long long score = dp[row-1][prev] - abs(col - prev);
              maxi = max(maxi, score);
            }
            dp[row][col] = pts[row][col] + maxi;
          }
        }
        
        // Answer = max of last row
        return *max_element(dp[m-1].begin(), dp[m-1].end());
      }

      long long tabulation2(vector<vector<int>>& pts) {

          int m = pts.size();
          int n = pts[0].size();
          vector<long long> prev(n), curr(n);
          
          // Base case
          for(int col = 0; col < n; col++){
            prev[col] = pts[0][col];
          }
          
          for (int row = 1; row < m; row++) {
            
            vector<long long> left(n), right(n);
            
            // Left to right pass
            left[0] = prev[0];
            for (int col = 1; col < n; col++) {
              left[col] = max(prev[col], left[col-1] - 1);
            }
            
            // Right to left pass
            right[n-1] = prev[n-1];
            for (int col = n-2; col >= 0; col--) {
              right[col] = max(prev[col], right[col+1] - 1);
            }
            
            // Compute current row
            for (int col = 0; col < n; col++) {
              curr[col] = pts[row][col] + max(left[col], right[col]);
            }
            
            prev = curr;
          }
          
          return *max_element(prev.begin(), prev.end());
      }

public:
    long long maxPoints(vector<vector<int>>& points) {
        
        // int m = points.size();
        // int n = points[0].size();

        // Recursion (TLE)
        // long long ans = LLONG_MIN;
        // for (int col = 0; col < n; col++) {
        //   ans = max(ans, recur(m-1, col, points));
        // }
        // return ans;

        // TopDown
        // vector<vector<long long>> dp(m, vector<long long>(n, -1));
        // long long ans = LLONG_MIN;
        // for (int c = 0; c < n; c++) {
        //   ans = max(ans, recurMemo(m-1, c, points, dp));
        // }
        // return ans;

        // Tabulation
        // return tabulation(points);

        // Optimized
        return tabulation2(points);
        
    }
};