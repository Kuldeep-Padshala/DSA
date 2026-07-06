// LC: 42 h 

class Solution {
public:
    int trap(vector<int>& height) {    

        // two loops TLE

        // int n=height.size();
        // int ans=0;

        // for(int i=1; i<n-1; i++){

        //     int left_max=height[i];
        //     for(int j=i-1; j>=0; j--){
        //         left_max=max(left_max,height[j]);
        //     }

        //     int right_max=height[i];
        //     for(int j=i+1;j<n;j++){
        //       right_max=max(right_max,height[j]);
        //     }
        //     ans+=min(left_max,right_max)-height[i];
        // }
        // return ans;
        

        // two pinter 

        int n = height.size();

        int left_height = height[0];
        int right_height = height[n-1];
        int ans = 0;

        // left_height:  0  1     2
        // right_height: 1     2  
        // height[s]:    0  1
        // height[e]:    1  1  2
        // s             0  1     2
        // e            10     9
        // ans           0  0     1

        int s = 0;
        int e = n-1;

        while (s < e) {
          
          if (left_height < right_height) {

              s++;
              ans += max(0, left_height - height[s]);             // Fill in the gap.
              left_height = max(left_height, height[s]);          // Update current max height from left.
          }
          else {

              e--;
              ans += max(0, right_height - height[e]);            // Fill in the gap.
              right_height = max(right_height, height[e]);         // Update current max height from right.
          }
        }

        return ans;

    }
};