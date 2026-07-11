// LC: 560 m 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        // Hashing

        int n=nums.size();

        unordered_map<int,int>mp;
        mp[0]=1;

        int pre_sum=0;
        int ans=0;

        for(int i=0; i<n; i++){

          pre_sum+=nums[i];
          if(mp.find(pre_sum-k)!=mp.end()){
            ans+=mp[pre_sum-k];
          }

          mp[pre_sum]++;
        }
        return ans;


        // n*n

        // int n = nums.size();
        // int count = 0;

        // for(int i=0; i<n; i++){
          
        //   int sum=0;
        //   for(int j=i; j<n; j++){
            
        //     sum += nums[j];
        //     if(sum==k){
        //       count++;
        //     }
        //   }
        // }
        // return count;
    }
};