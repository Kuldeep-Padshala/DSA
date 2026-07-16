// LC: 2731 m 

// ants on a plank + prefix sum

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        
        // prefix sum

        long long n = nums.size();
        int MOD = 1000000007;

        vector<long long> pos(n);

        for(int i=0; i<n; i++){

          if(s[i] == 'R'){
            pos[i] = (long long)nums[i] + d;
          }
          else{
            pos[i] = (long long)nums[i] - d;
          }
        }

        long long ans = 0;
        long long prefixSum = 0;
        sort(pos.begin(), pos.end());

        for(int i=0; i<n; i++){

          ans += i * (long long) pos[i] - prefixSum;
          ans %= MOD;
          prefixSum += pos[i];
        }
        return ans;
    }
};