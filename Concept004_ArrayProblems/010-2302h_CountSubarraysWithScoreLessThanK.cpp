// LC: 2302 h 

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long sum = 0;
        long long ans = 0;
        int s = 0;
        
        for(int e=0; e<nums.size(); e++){
            
          sum += nums[e];
          
          // Shrink window if score >= k
          while(sum * (e-s+1) >= k){
            sum -= nums[s];
            s++;
          }
          
          // All subarrays ending at e are valid
          ans += (e-s+1);
        }
        
        return ans;


    }
};