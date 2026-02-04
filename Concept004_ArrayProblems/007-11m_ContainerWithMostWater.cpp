// LC: 11 m 

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // Two Pointers

        int n = height.size();
        int maxWater = 0;
        int s=0, e=n-1;


        while(s<e){
            
          int width = e-s;
          int minHeight = min(height[s], height[e]);
          maxWater = max(maxWater, width * minHeight);

          if(height[s] < height[e]){
            s++;
          }
          else{
            e--;
          }
        }
        
        return maxWater;
    }
};