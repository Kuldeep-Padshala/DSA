// LC: 368 m 

class Solution {

      vector<int> getLIS(vector<int>& arr) {
        
        // Code here
        int n = arr.size();
        vector<int> dp(n, 1), hash(n); 
        int maxi = 1, lastIdx = 0;
        
        for(int i=0; i<n; i++){
            
          hash[i] = i;
          for(int prev=0; prev<i; prev++){
              
            if(arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i]){
              dp[i] = 1 + dp[prev];
              hash[i] = prev;
            }
          }
          if(dp[i] > maxi){
            maxi = dp[i];
            lastIdx = i;
          }
        }
        
        vector<int> ans(maxi);
        ans[maxi-1] = arr[lastIdx];
        int i = maxi-2;
        
        while(hash[lastIdx] != lastIdx){
          lastIdx = hash[lastIdx];
          ans[i--] = arr[lastIdx];
        }
        return ans;
      }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        return getLIS(nums);
    }
};