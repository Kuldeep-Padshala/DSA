// LC: 2100 m 

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {

        
        // prefix sum

        int n = security.size();
        
        // There are at least time days before and after the ith day
        // good days must be between 0+time days to (n-1)-time days

        // sec[i - time] >= sec[i - time + 1] >= ... >= sec[i] <= ... <= sec[i + time - 1] <= sec[i + time]


        vector<int> prefixSum(n,0);
        vector<int> suffixSum(n,0);

        int cnt=1;
        prefixSum[0] = 1;

        for(int i=1; i<n; i++){    
          
          if(security[i] <= security[i-1]){
            cnt++;
          }
          else{
            cnt=1;
          }
          prefixSum[i]=cnt;
        }


        cnt=1;
        suffixSum[n-1] = 1;

        for(int i=n-2;i>=0; i--){
            
          if(security[i] <= security[i+1]){
            cnt++;
          }
          else{
            cnt=1;
          }
          suffixSum[i]=cnt; 
        }

        vector<int>ans;
        for(int i=0; i<n; i++){

          if(prefixSum[i]-1 >= time && suffixSum[i]-1 >= time){
            ans.push_back(i);
          }
        }
            
        return ans;
        

        // int n = security.size();
        // vector<int> prefixNonIncreasing(n, 0);
        // vector<int> prefixNonDecreasing(n, 0);

        // for(int i=1; i<n; i++){
        //   prefixNonIncreasing[i] = prefixNonIncreasing[i-1] + (security[i] <= security[i-1] ? 1 : 0);
        //   prefixNonDecreasing[n-i-1] = prefixNonDecreasing[n-i] + (security[n-i-1] <= security[n-i] ? 1 : 0);
        // }

        // vector<int> ans;

        // for(int i=time; i<n-time; i++){
        //   if(prefixNonIncreasing[i] >= time && prefixNonDecreasing[i] >= time){
        //     ans.push_back(i);
        //   }
        // }
        // return ans;
    }
};