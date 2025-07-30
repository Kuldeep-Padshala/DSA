// LC: 2006 e

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        int count = 0;

        for(int num : nums){

          freq[num]++;
          count += freq[num-k] + freq[num+k];   // current elem na +-k jetla num ni frequncy add

        }
        return count;
    }
};