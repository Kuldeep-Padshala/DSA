// LC: 1458 h 

class Solution {

      // LC: 1143 LCS, but for array
      int tabulation(vector<int>& nums1, vector<int>& nums2){

        int n = nums1.size(), m = nums2.size();
        const int NEG_INF = -1e9;

        vector<vector<int>> dp(n+1, vector<int>(m+1, NEG_INF));

        for(int i=1; i<=n; i++) {
          for (int j=1; j<=m; j++) {

              int prod = nums1[i-1] * nums2[j-1];

              dp[i][j] = max({
                prod,
                prod + dp[i-1][j-1],
                dp[i-1][j],
                dp[i][j-1]
              });
          }
        }
        return dp[n][m];
      }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        return tabulation(nums1, nums2);
    }
};