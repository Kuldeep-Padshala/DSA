// Leetcode 3005 e

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int> count;
        int ans=0, maxF=0;

        // for(int &num : nums){
        //   count[num]++;
        //   maxF = max(maxF, count[num]);
        // }

        // for(int &num : nums){
        //   if(count[num] == maxF){
        //     ans++;
        //   }
        // }

        for(int &num : nums){
          count[num]++;
          if(count[num] > maxF){
            maxF = count[num];
            ans = maxF;
            continue;
          }
          if(count[num] == maxF){
            ans+=maxF;
            continue;
          }
        }
        return ans;
    }
};