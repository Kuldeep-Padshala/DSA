// LC: 3129 m 

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long recurMemo(int prev, int zeroes, int ones, int limit, auto& dp) {

        // base case
        if(zeroes == 0 && ones == 0){
          return 1;
        }
        if(zeroes < 0 || ones < 0){
          return 0;
        }

        // check dp
        if(dp[prev][zeroes][ones] != -1){
          return dp[prev][zeroes][ones];
        }

        long long ans = 0;
        if(prev){
          
          for(int i=1; i <= limit; i++){
            ans += recurMemo(0, zeroes-i, ones, limit, dp);
          }
        }

        else{

          for(int i=1; i<=limit; i++){
            ans += recurMemo(1, zeroes, ones - i, limit, dp);
          }
        }

        return dp[prev][zeroes][ones] = ans % MOD;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(201, vector<int>(201, -1)));

        long long ans = 0;

        for(int i=1; i<=limit; i++){
          ans += recurMemo(0, zero - i, one, limit, dp);
        }
        for(int i=1; i<=limit; i++){
          ans += recurMemo(1, zero, one - i, limit, dp);
        }

        return ans % MOD;
        return 0;
    }
};