// LC: 2996 e imp 

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int n = nums.size();
        int maxSum = nums[0], curr = nums[0];
        int maxi = nums[0];
        bool Continue = true;
        unordered_set<int> st;
        st.insert(nums[0]);

        for(int i=1; i<n; i++){

          if(nums[i] == nums[i-1] + 1 && Continue){
            curr += nums[i];
            maxSum = curr;
          }
          else{
            Continue = false;
          }

          maxi = max(maxi, nums[i]);
          st.insert(nums[i]);
        }

        if(maxSum > maxi) return maxSum;

        for(int i=maxSum; i<=maxi+1; i++){
          if(st.find(i) == st.end()){
            return i;
          }
        }

        return maxSum;
    }
};