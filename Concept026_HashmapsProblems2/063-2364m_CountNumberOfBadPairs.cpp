// LC: 2364 m 

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long n = nums.size();
        unordered_map<int, int> mp;
        long long goodPairs = 0;
        
        for(int i = 0; i<n; i++){
          
          int key = nums[i] - i;
          goodPairs += mp[key];
          mp[key]++;
        }
        
        return (n*(n-1)) / 2 - goodPairs;
    }
};