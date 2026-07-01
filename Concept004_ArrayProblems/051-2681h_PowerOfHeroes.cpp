// LC: 2681 h 

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        
        // prfinum sum

        int MOD = 1000000007;

        sort(nums.begin(), nums.end());

        long long ans = 0;
        long long prefix = 0;   // weighted sum of minimums

        for(long long num : nums){

            long long contribution = (num * num) % MOD;

            ans = (ans + contribution * (num + prefix)) % MOD;

            prefix = (prefix * 2 + num) % MOD;
        }

        return ans;

        // int MOD = 1000000007;

        // int n = nums.size();
        // vector<int> manumi, mini;

        // manumi.push_back(nums[0]);
        // mini.push_back(nums[0]);

        // for(int i=1; i<n; i++){
          
        //   manumi.push_back(manum(nums[i], manumi[i-1]));
        //   mini.push_back(min(nums[i], mini[i-1]));
        // }

        // long long ans = 0;


    }
};