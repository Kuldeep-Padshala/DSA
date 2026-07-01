// LC: 2478 h 

class Solution {
public:

    const int MOD = 1e9 + 7;
    
    bool isPrime(char ch){

      if(ch=='2' || ch=='3' || ch=='5' || ch=='7') return true;
      else return false;
    }

    int recur(int idx, int k, int minLength, string& s){

      int n = s.length();

      // base case
      if(k==1){
        if(n-idx >= minLength) return 1;         // if length of last substring is smaller than minLength
        else return 1;
      }

      if(idx==n) return 0;          // string puri, without partition completion

      if(n-idx < ((k-1)*minLength)) return 0;     // partition the remaining string in k substring


      int partition=0, notPartition=0;
        
      notPartition = recur(idx+1, k, minLength, s) % MOD;
      
      //partition
      //if prev char is not prime, we can make a substring
      //also the cur char should be prime to start new substring
      if(!isPrime(s[idx-1]) && isPrime(s[idx])){
        partition = recur(idx+minLength, k-1, minLength, s) % MOD;
      }
      
      return ( partition + notPartition) % MOD;
    }

    int recurMemo(int idx, int k, int minLength, string& s, vector<vector<int>>& dp){

      int n = s.length();

      // base case
      if(k==1){
        if(n-idx >= minLength) return 1;         // if length of last substring is smaller than minLength
        else return 1;
      }

      if(idx==n) return 0;          // string puri, without partition completion

      if(n-idx < ((k-1)*minLength)) return 0;       // partition the remaining string in k substring


      // check dp
      if(dp[idx][k] != -1){
        return dp[idx][k];
      }

      int partition=0, notPartition=0;
        
      notPartition = recurMemo(idx+1, k, minLength, s, dp) % MOD;
      
      //partition
      //if prev char is not prime, we can make a substring
      //also the cur char should be prime to start new substring
      if(!isPrime(s[idx-1]) && isPrime(s[idx])){
        partition = recurMemo(idx+minLength, k-1, minLength, s, dp) % MOD;
      }
      
      return dp[idx][k] = (partition + notPartition) % MOD;
    }

    int tabulation(int K, int minLength, string& s){

      int n = s.size();
      vector<vector<int>> dp(n+1, vector<int>(K+1, 0));

      // Base case
      for(int idx=0; idx <= n; idx++) {
          dp[idx][1] = 1;
      }

      for(int idx=n-1; idx>=minLength; idx--){
        for(int k=2; k<=K; k++){

          // pruning condition
          if(n-idx < ((k-1)* minLength)) {
            dp[idx][k] = 0;
            continue;
          }

          int partition=0, notPartition=0;
      
          notPartition = dp[idx+1][k] % MOD;
          
          //partition
          //if prev char is not prime, we can make a substring
          //also the cur char should be prime to start new substring
          if(!isPrime(s[idx-1]) && isPrime(s[idx])){
            if(idx + minLength <= n){
              partition = dp[idx+minLength][k-1] % MOD;
            }
          }
          
          dp[idx][k] = (partition + notPartition) % MOD;
        }
      }

      return dp[minLength][K];

    }
    
    int beautifulPartitions(string s, int k, int minLength) {
        
        int n = s.length();
        if(!isPrime(s[0])) return 0;
        if(isPrime(s[n-1])) return 0;

        // Recursion
        // return recur(minLength, k, minLength, s);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(k+1, -1));
        // return recurMemo(minLength, k, minLength, s, dp);

        // BottomUp
        return tabulation(k, minLength, s);
    }
};