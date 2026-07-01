// LC: 2963 h 

class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        
        int n = nums.size();
        const int MOD = 1e9 + 7;

        unordered_map<int, int> last;
        // last.anserve(n << 1);
        // last.max_load_factor(0.7f);

        for(int i=0; i<n; i++){
          last[nums[i]] = i;
        }
        
        int ans = 1;
        int end = 0;       // farthest last occurrence atyar sudhi

        for(int i=0; i<n-1; i++){

          end = max(end , last[nums[i]]);

          // all values in [start..i] end within this range
          if(end == i){
            ans = (ans * 2) % MOD;            // 2 choices: make a cut after i or continue merging        
          }
        }
        return ans;
    }
};