// LC: 1048 m 

class Solution {

      static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
      }

      bool checkPossible(string &s1, string&s2){

        if(s1.size() != s2.size()+1) return false;

        int first = 0, second = 0;

        while(first < s1.size()){
          
          if(s1[first] == s2[second]){
            first++;
            second++;
          }
          else{
            first++;
          }
        }

        if(first==s1.size() && second==s2.size()) return true;
        return false;
      }

      // LIS
      int getLIS(vector<string>& arr) {
       
        // Code here
        int n = arr.size();
        vector<int> dp(n, 1);
        int maxi = 1, lastIdx = 0;
        
        for(int i=0; i<n; i++){
            
          // hash[i] = i;
          for(int prev=0; prev<i; prev++){
              
            if(checkPossible(arr[i], arr[prev]) && 1 + dp[prev] > dp[i]){
              dp[i] = 1 + dp[prev];
              // hash[i] = prev;
            }
          }
          if(dp[i] > maxi){
            maxi = dp[i];
            // lastIdx = i;
          }
        }
      
        return maxi;
      }

public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), comp);
        return getLIS(words);
    }
};