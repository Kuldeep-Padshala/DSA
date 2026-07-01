// LC: 1035 m 

class Solution {

      // LC: 1143 LCS, but for array
      int spaceOpt(vector<int>& nums1, vector<int>& nums2){

        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> prev(m+1, 0);

        for(int i=1; i<=n; i++){
          
          vector<int> curr(m+1, 0);
          for(int j=1; j<=m; j++){

            if(nums1[i-1] == nums2[j-1]){
              curr[j] = 1 + prev[j-1];
            }
            else{
              int case1 = prev[j];
              int case2 = curr[j-1];
              curr[j] = max(case1, case2);
            }
          }
          prev = curr;
        }
        return prev[m];
      }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        return spaceOpt(nums1, nums2);
    }
};