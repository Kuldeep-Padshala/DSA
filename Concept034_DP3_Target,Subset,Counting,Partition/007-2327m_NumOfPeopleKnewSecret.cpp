// LC:2327 m

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        const int MOD = 1000000007;

        // aya dp[i] means num of new people learns on ith day
        vector<long long> dp(n+1, 0);

        dp[1] = 1;
        long long new_today = 0;

        for (int day=2; day<=n; day++) {

          // new added
          if (day - delay >= 1){
            new_today += dp[day - delay];
            new_today =  new_today % MOD;
          }

          // old removed
          if (day - forget >= 1){
            new_today -= dp[day - forget];
            new_today = (new_today + MOD) % MOD ;       // minus kairu chhe, may be negative hoi sake.
          }

          // people who learn today = current active new_today
          dp[day] = new_today;
        }

        // count people who still remember by day n
        long long ans = 0;
        for (int day = n - forget + 1; day <= n; day++) {
          if (day >= 1){
            ans = (ans + dp[day]) % MOD;
          }
        }
        return ans;
    }
};