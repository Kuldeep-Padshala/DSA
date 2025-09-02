// LC:560 m 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> pref_sum;
        pref_sum[0]=1;
        int sum=0, ans=0;

        for(int num: nums){          // 123  3

          sum += num;

          // if there exist any prefix with sum, prefix = sum-k

          if(pref_sum.count(sum-k)){    // for 12, count(3-3 present so add)  3 mate count(6-3) present
            ans += pref_sum[sum-k];
          }
          pref_sum[sum]++;
        }
        return ans;
    }
};