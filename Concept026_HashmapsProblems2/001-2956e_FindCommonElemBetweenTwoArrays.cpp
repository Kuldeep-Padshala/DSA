// LC: 2956 e 

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s1, s2;

        for(int num: nums1){
          s1.insert(num);
        }
        for(int num: nums2){
          s2.insert(num);
        }
        
        vector<int> ans(2, 0);

        for(int num: nums1){
          if(s2.count(num)) ans[0]++;
        }

        for(int num: nums2){
          if(s1.count(num)) ans[1]++;
        }

        return ans;
    }
};