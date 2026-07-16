// LC: 2848 e 

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        
        // line sweep
        
        int n = nums.size();
        vector<int> line(102);

        int points_on_line = 0;

        for(int i=0; i<n; i++){
          
            int s = nums[i][0];
            int e = nums[i][1];
            line[s] += 1;
            line[e+1] -= 1;
        }

        for(int i=1; i<102; i++){
            
            line[i] += line[i-1];

            if(line[i] != 0){
              points_on_line += 1;
            }
        }

        return points_on_line;


        // hashmaps

        // unordered_set<int> uniq{};
        // for(vector<int> v : nums){
            
        //     int n = v.size();
        //     for(int i=v[0]; i<=v[n-1]; i++){
        //       uniq.insert(i);
        //     }
        // }
        // return uniq.size();
    }
};