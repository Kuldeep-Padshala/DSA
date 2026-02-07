// LC: 238 m

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // Optimized Prefix and Suffix Approach

        int n = nums.size();

        vector<int> Lp(n);

        Lp[0] = 1;

        for(int i=1; i<n; i++){
          Lp[i] = Lp[i-1] * nums[i-1];
        }

        int Rp = 1;
        for(int i=n-2; i>=0; i--){    // static_cast<int> (n)
          Rp *= nums[i+1];
          Lp[i] = Lp[i] * Rp;
        }

        return Lp;
        
        // devide method

        // int n=nums.size();
        // vector<int>ans;
        // int product=1;
        // int count=0;

        // for(int i=0; i<n; i++){

        //   if(nums[i]==0){
        //     count++;
        //   }
        //   else{
        //     product *= nums[i];
        //   }
        // }

        // for(int i=0; i<n; i++){

        //     if(nums[i]!=0){
        //       if(count==0){
        //         ans.push_back(product/nums[i]);
        //       }
        //       else{
        //         ans.push_back(0);
        //       }
        //     }
        //     else{
        //       if(count==1) {
        //         ans.push_back(product);
        //       }
        //       else{
        //         ans.push_back(0);
        //       }
        //     }
        // }
        // return ans;
    }
};