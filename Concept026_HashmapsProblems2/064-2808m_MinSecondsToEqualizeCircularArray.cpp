// LC: 2808 m 

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> pos, gap;

        for(int i=0; i<n*2; i++){
          
          int num = nums[i%n];
          
          if(pos.find(num) != pos.end()){
            gap[num] = max(gap[num], (i - pos[num]) / 2);
          }
          pos[num] = i;
        }

        int mini = min_element(begin(gap), end(gap), [](auto &p1, auto &p2){
          return p1.second < p2.second;
        })->second;

        return mini;
    }
};