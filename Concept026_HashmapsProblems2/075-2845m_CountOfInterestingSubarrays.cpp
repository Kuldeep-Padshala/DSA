// LC: 2845 m 

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        
        long long count = 0, equals = 0;
        unordered_map<int, long long> mp;
        mp[0] = 1;

        for(int num: nums){
          
          if(num % modulo == k) equals++;

          int rem = equals % modulo;
          int needed = (rem - k + modulo) % modulo;

          count += mp[needed];
          mp[rem]++;
        }

        return count;
    }
};