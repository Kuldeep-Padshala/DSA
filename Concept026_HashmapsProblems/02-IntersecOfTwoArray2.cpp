// LC: 350 e

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> count;
        vector<int> ans;

        for(int num : nums1){
          count[num]++;
        }

        for(int num : nums2){

          if( count[num] > 0 ){   // we are not checking here the key num is there or not, but what is its valle

            ans.push_back(num);
            count[num]--;
          }
        }
        return ans;
    }
};