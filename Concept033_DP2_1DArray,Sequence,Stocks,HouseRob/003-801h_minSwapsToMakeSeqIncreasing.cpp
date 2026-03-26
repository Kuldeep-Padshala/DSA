// LC: 801 h 

class Solution {

      int recur(int idx, bool swapped, vector<int>& nums1, vector<int>& nums2){

        // Base case
        if(idx == nums1.size()){
          return 0;
        }

        int prev1, prev2;
        if(idx == 0){                  // peli row mate
          prev1 = -1;
          prev2 = -1;
        }
        else{
          if(swapped){               // jo prev idx ma swap thayelu hoi to -> nums1 ma nums2 na last element jovano 
            prev1 = nums2[idx-1];    // cause apde input array ma change nathi karta
            prev2 = nums1[idx-1];
          }
          else{
            prev1 = nums1[idx-1];
            prev2 = nums2[idx-1];
          }
        }

        int ans = INT_MAX;

        // no swap
        if(nums1[idx] > prev1 && nums2[idx] > prev2){
          ans = recur(idx+1, false, nums1, nums2);
        }
        if(nums1[idx] > prev2 && nums2[idx] > prev1){
          ans = min(ans, 1+recur(idx+1, true, nums1, nums2));
        }
        return ans;
        
      }

      int recurMemo(int idx, bool swapped, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){

        // Base case
        if(idx == nums1.size()){
          return 0;
        }

        // Check dp
        if(dp[idx][(int)swapped] != -1){
          return dp[idx][(int)swapped];
        }

        int prev1, prev2;
        if(idx == 0){                  // peli row mate
          prev1 = -1;
          prev2 = -1;
        }
        else{
          if(swapped){               // jo prev idx ma swap thayelu hoi to -> nums1 ma nums2 na last element jovano 
            prev1 = nums2[idx-1];    // cause apde input array ma change nathi karta
            prev2 = nums1[idx-1];
          }
          else{
            prev1 = nums1[idx-1];
            prev2 = nums2[idx-1];
          }
        }

        int ans = INT_MAX;

        // no swap
        if(nums1[idx] > prev1 && nums2[idx] > prev2){
          ans = recurMemo(idx+1, false, nums1, nums2, dp);
        }
        if(nums1[idx] > prev2 && nums2[idx] > prev1){
          ans = min(ans, 1+recurMemo(idx+1, true, nums1, nums2, dp));
        }
        return dp[idx][(int)swapped] = ans; 
      }

      int tabulation(vector<int>& nums1, vector<int>& nums2){

        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int idx=n-1; idx>=0; idx--){
          for(int swapped=1; swapped>=0; swapped--){

              int prev1, prev2;
              if(idx == 0){                  // peli row mate
                prev1 = -1;
                prev2 = -1;
              }
              else{
                if(swapped){               // jo prev idx ma swap thayelu hoi to -> nums1 ma nums2 na last element jovano 
                  prev1 = nums2[idx-1];    // cause apde input array ma change nathi karta
                  prev2 = nums1[idx-1];
                }
                else{
                  prev1 = nums1[idx-1];
                  prev2 = nums2[idx-1];
                }
              }

              int ans = INT_MAX;

              // no swap
              if(nums1[idx] > prev1 && nums2[idx] > prev2){
                ans = dp[idx+1][0];
              }
              if(nums1[idx] > prev2 && nums2[idx] > prev1){
                ans = min(ans, 1+dp[idx+1][1]);
              }
              dp[idx][swapped] = ans; 
          }
        }
        return dp[0][0];
      }

      int spaceOpt(vector<int>& nums1, vector<int>& nums2){

        int n = nums1.size();
        int nextSwap=0, nextNoswap=0;

        for(int idx=n-1; idx>=0; idx--){

          int currSwap=INT_MAX, currNoswap=INT_MAX;

          for(int swapped=1; swapped>=0; swapped--){

              int prev1, prev2;
              if(idx == 0){                  // peli row mate
                prev1 = -1;
                prev2 = -1;
              }
              else{
                if(swapped){               // jo prev idx ma swap thayelu hoi to -> nums1 ma nums2 na last element jovano 
                  prev1 = nums2[idx-1];    // cause apde input array ma change nathi karta
                  prev2 = nums1[idx-1];
                }
                else{
                  prev1 = nums1[idx-1];
                  prev2 = nums2[idx-1];
                }
              }

              int ans = INT_MAX;

              // no swap
              if(nums1[idx] > prev1 && nums2[idx] > prev2){
                ans = nextNoswap;
              }
              if(nums1[idx] > prev2 && nums2[idx] > prev1){
                ans = min(ans, 1 + nextSwap);
              }
              if(swapped) currSwap = ans;
              else currNoswap = ans;
          }
          nextSwap = currSwap;
          nextNoswap = currNoswap;
        }
        return min(nextSwap, nextNoswap);
      }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        // int n = nums1.size();
        // Recursion
        // return recur(0, false, nums1, nums2);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return recurMemo(0, false, nums1, nums2, dp);

        // BottomUp
        // return tabulation(nums1, nums2);

        // Space optimization
        return spaceOpt(nums1, nums2);
    }
};