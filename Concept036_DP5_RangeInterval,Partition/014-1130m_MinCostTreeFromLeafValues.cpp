// LC: 1130 m 

// partition dp with precomputed max

class Solution {

      int recur(vector<int>& arr, map<pair<int,int>, int>& maxi, int s, int e){

        // Base case
        if(s==e) return 0;      // leaf

        int ans = INT_MAX;

        for(int mid=s; mid<e; mid++){
          ans = min(ans, 
                  maxi[{s, mid}]*maxi[{mid+1, e}] +
                  recur(arr, maxi, s, mid) +
                  recur(arr, maxi, mid+1, e)
          );
        }
        return ans;

      }

      int recurMemo(vector<int>& arr, map<pair<int,int>, int>& maxi, int s, int e, vector<vector<int>>& dp){

        // Base case
        if(s==e) return 0;      // leaf

        // check dp
        if(dp[s][e] != -1){
          return dp[s][e];
        }

        int ans = INT_MAX;

        for(int mid=s; mid<e; mid++){
          ans = min(ans, 
                  maxi[{s, mid}]*maxi[{mid+1, e}] +
                  recurMemo(arr, maxi, s, mid, dp) +
                  recurMemo(arr, maxi, mid+1, e, dp)
          );
        }
        return dp[s][e] = ans;
      }

      int tabulation(vector<int>& arr, map<pair<int,int>, int>& maxi){

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int s=n-1; s>=0; s--){
          for(int e=s+1; e<n; e++){

            int ans = INT_MAX;

            for(int mid=s; mid<e; mid++){
              ans = min(ans, 
                      maxi[{s, mid}]*maxi[{mid+1, e}] +
                      dp[s][mid] +
                      dp[mid+1][e]
              );
            }
            dp[s][e] = ans;

          }
        }

        return dp[0][n-1];

      }

public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int n = arr.size();

        // Precompute
        map<pair<int,int>, int> maxi;

        for(int i=0; i<n; i++){

          maxi[{i, i}] = arr[i];
          for(int j=i+1; j<n; j++){
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
          }
        }

        // Recursion
        // return recur(arr, maxi, 0, n-1);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return recurMemo(arr, maxi, 0, n-1, dp);

        // BottomUp
        return tabulation(arr, maxi);
    }
};