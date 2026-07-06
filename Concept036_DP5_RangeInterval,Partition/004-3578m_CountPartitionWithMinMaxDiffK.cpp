// LC: 3578 m

class Solution {

      const int MOD = 1000000007;

      int recur(int idx, int mini, int maxi, int k, vector<int>& nums){

        int Mini = mini, Maxi = maxi;
        if(nums[idx] < mini){
          Mini = nums[idx];
        }
        if(nums[idx] > maxi){
          Maxi = nums[idx];
        }

        // Base case
        if(idx == 0){
          if(abs(Maxi - Mini) > k){
            return 1;
          }
          else{
            return 2;
          }
        }

        if(abs(Maxi - Mini) > k){
          return recur(idx-1, nums[idx], nums[idx], k, nums);
        }
        else{
          return recur(idx-1, Mini, Maxi, k, nums) + recur(idx-1, nums[idx], nums[idx], k, nums);
        }
      }

      int recurMemo(int idx, int mini, int maxi, int k, vector<int>& nums, vector<map<pair<int,int>,int>>& dp){

        // Memo check
        auto key = make_pair(mini, maxi);

        // check dp
        if(dp[idx].count(key)){
          return dp[idx][key];
        }

        int Mini = mini, Maxi = maxi;
        if(nums[idx] < mini){
          Mini = nums[idx];
        }
        if(nums[idx] > maxi){
          Maxi = nums[idx];
        }

        int ans;

        // Base case
        if(idx == 0){
          if(abs(Maxi - Mini) > k){
            return dp[idx][key] = 1;
          }
          else{
            return dp[idx][key] = 2;
          }
        }

        if(abs(Maxi - Mini) > k){
            return dp[idx][key] = recurMemo(idx-1, nums[idx], nums[idx], k, nums, dp) % MOD;
        }
        else{
            long long a = recurMemo(idx-1, Mini, Maxi, k, nums, dp);
            long long b = recurMemo(idx-1, nums[idx], nums[idx], k, nums, dp);
            return dp[idx][key] = (a + b) % MOD;
        }
      }

      int tabulation(int k, vector<int>& nums){

        int n = nums.size();

        vector<long long> dp(n, 0);
        const int MOD = 1e9+7;

        for(int i = 0; i < n; i++){

          long long mini = nums[i];
          long long maxi = nums[i];

          for (int j = i; j >= 0; j--) {

              mini = min(mini, (long long)nums[j]);
              maxi = max(maxi, (long long)nums[j]);

              if (maxi - mini > k) break;

              if (j == 0) dp[i] = (dp[i] + 1) % MOD;
              else dp[i] = (dp[i] + dp[j-1]) % MOD;
          }
        }

      return dp[n-1];
      }

public:
    int countPartitions(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n==1){
          return 1;
        }

        // Recursion
        // return recur(n-2, nums[n-1], nums[n-1], k, nums) % 1000000007;

        // TopDown (TLE)
        // vector< map<pair<int,int>, int> > dp(n);
        // return recurMemo(n-2, nums[n-1], nums[n-1], k, nums, dp);

        // BottomUP (TLE)
        // return tabulation(k, nums);

        deque<int> max_dq, min_dq;
        vector<int> dp(size(nums) + 1);
        dp[0] = 1;
        for (int right = 0, left = 0, suffix = 0; right < size(nums); ++right) {
            suffix = (suffix + dp[right]) % MOD;
            while (!empty(max_dq) && nums[max_dq.back()] <= nums[right]) {
                max_dq.pop_back();
            }
            max_dq.emplace_back(right);
            while (!empty(min_dq) && nums[min_dq.back()] >= nums[right]) {
                min_dq.pop_back();
            }
            min_dq.emplace_back(right);
            while (nums[max_dq[0]] - nums[min_dq[0]] > k) {
                if (max_dq[0] == left) {
                    max_dq.pop_front();
                }
                if (min_dq[0] == left) {
                    min_dq.pop_front();
                }
                suffix = (((suffix - dp[left++]) % MOD) + MOD) % MOD;
            }
            dp[right + 1] = suffix;
        }
        return dp.back();
    }
};