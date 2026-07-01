// LC: 1043 m 

class Solution {

      int recur(int idx, vector<int>& arr, int size){

        // Base case
        if(idx == -1) return 0;

        int len = 0;
        int maxElem = INT_MIN;
        int maxSum = INT_MIN;

        for(int k = idx; k >= max(0, idx-size+1); k--){
          len++;
          maxElem = max(maxElem, arr[k]);

          int currSum = len*maxElem + recur(k-1, arr, size);
          maxSum = max(maxSum, currSum);
        }
        return maxSum;
      }

      int recurMemo(int idx, vector<int>& arr, int size, vector<int>& dp){

        // Base case
        if(idx == -1) return 0;

        // check dp
        if(dp[idx] != -1){
          return dp[idx];
        }

        int len = 0;
        int maxElem = INT_MIN;
        int maxSum = INT_MIN;

        for(int k = idx; k >= max(0, idx-size+1); k--){
          len++;
          maxElem = max(maxElem, arr[k]);

          int currSum = len*maxElem + recurMemo(k-1, arr, size, dp);
          maxSum = max(maxSum, currSum);
        }
        return dp[idx] = maxSum;
      }

      int tabulation(vector<int>& arr, int size){

        int n = arr.size();
        vector<int> dp(n, 0);

        for(int idx=0; idx<n; idx++){
          
          int len = 0;
          int maxElem = INT_MIN;
          int maxSum = INT_MIN;

          for(int k=idx; k >= max(0, idx-size+1); k--){
            len++;
            maxElem = max(maxElem, arr[k]);

            int currSum = (k>0) ? (len*maxElem + dp[k-1]) : (len*maxElem + 0);
            maxSum = max(maxSum, currSum);
          }
          dp[idx] = maxSum;
        }
        return dp[n-1];
      }
      
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();

        // Recursion
        // return recur(n-1, arr, k);

        // TopDown
        // vector<int> dp(n, -1);
        // return recurMemo(n-1, arr, k, dp);

        // BottomUP
        return tabulation(arr, k);
    }
};