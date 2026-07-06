// LC: 1218 m 

class Solution {

      int recur(int i, int d, vector<int>& arr){

        // Base case
        if(i<0){
          return 0;
        }

        int ans = 0;
        for(int left = i-1; left>=0; left--){
          if(arr[i]-arr[left] == d){
            // plus 1 for counting current, left
            ans = max(ans, 1 + recur(left, d, arr));
          }
        }
        return ans;
      }

      int tabulation(int diff, vector<int>& arr){

        unordered_map<int, int> dp;
        int ans = 0;

        for(int& curr: arr){

          int prev = curr - diff; 
          int prevCnt;

          if(dp.count(prev)){
            prevCnt = dp[prev];
          }
          else{
            prevCnt = 0;
          }

          dp[curr] = 1 + prevCnt;

          ans = max(ans, dp[curr]);
        }
        return ans;
      }

public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        // int n = arr.size();
        // if(n<=2){
        //   return n;
        // }

        // Recursion
        // int ans = 1;

        // // apde arr[i] arr[j] ne last 2 elem of AP consider karsu.
        // // so for every i and j we will go left of i to check
        // for(int i=0; i<n; i++){
        //   for(int j=i+1; j<n; j++){
        //     if(arr[j] - arr[i] == difference){
        //       ans = max(ans, 2 + recur(i, difference, arr));    // plus 2 for i and j, recur will give the left elements
        //     }
        //   }
        // }
        // return ans;


        // bottomUp
        return tabulation(difference, arr);
    }
};