// LC: 1726 m 

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> mp;

        int ans = 0;
        
        for(int i=0; i<n; i++){
          for(int j=i+1; j<n; j++){

            int product = nums[i]*nums[j];
            ans += 8 * mp[product];
            mp[product]++;
          }
        }
            
        return ans;
        
        // tle
        // int n = nums.size();
        // int ans = 0;

        // for(int i=0; i<n-3; i++){
        //   for(int j=i+1; j<n-2; j++){
        //     for(int k=j+1; k<n-1; k++){
        //       for(int l=k+1; l<n; l++){

        //         if(nums[i]*nums[j] == nums[k]*nums[l]) ans+=8;
        //         if(nums[i]*nums[k] == nums[j]*nums[l]) ans+=8;
        //         if(nums[i]*nums[l] == nums[k]*nums[j]) ans+=8;
        //       }
        //     }
        //   }
        // }
        // return ans;
    }
};