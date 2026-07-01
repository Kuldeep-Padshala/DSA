// LC: 2605 e 

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
              
            if(nums1[i] == nums2[j]){
              return nums1[i];
            }
          }
        }

        int a = min(nums1[0],nums2[0]);
        int b = max(nums1[0],nums2[0]);

        return a*10 + b;

        // unordered_set<int> set1(nums1.begin(), nums1.end());
        // unordered_set<int> set2(nums2.begin(), nums2.end());

        // int commonMin = INT_MAX;
        // int min1 = INT_MAX;
        // int min2 = INT_MAX;

        // for(int num: nums1){
            
        //   if(set2.count(num)){
        //     commonMin = min(commonMin, num);
        //   }
        //   min1 = min(min1, num);
        // }
      
        // for(int num: nums2){
        //   min2 = min(min2, num);
        // }

        // if(commonMin != INT_MAX){
        //   return commonMin;
        // }

        // return min(min1 * 10 + min2, min2 * 10 + min1);
    }
};