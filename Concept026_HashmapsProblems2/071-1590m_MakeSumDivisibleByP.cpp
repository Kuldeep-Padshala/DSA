// LC: 1590 m 

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n = nums.size();

        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = total % p;
        if(rem == 0){                   // no need to remove anything
          return 0;
        }

        unordered_map<int, int> mp;  // prefix_mod → index
        mp[0] = -1;                  // base case

        long long prefixSum = 0;
        int ans = n;

        for(int i=0; i<n; i++) {
            
          prefixSum = (prefixSum + nums[i]) % p;

          // We want prefixSum[j] = (prefixSum - rem + p) % p
          int target = (prefixSum - rem + p) % p;

          if(mp.count(target)){
            ans = min(ans, i - mp[target]);
          }

          // store latest index for this prefixSum mod
          mp[prefixSum] = i;
        }

        return ans == n ? -1 : ans;
    }
};