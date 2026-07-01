// LC: 930 m 

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int num: nums){
          sum += num; 
          count += mp[sum - goal];
          mp[sum]++; 
        }
        return count;
    }
};