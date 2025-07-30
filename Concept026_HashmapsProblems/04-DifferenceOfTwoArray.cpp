// LC: 2215 e

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, bool> map1, map2;
        vector<vector<int>> ans(2);

        for(int num: nums1){
          map1[num] = true;
        }
        for(int num: nums2){
          map2[num] = true;
        }

        for(auto it=map1.begin(); it!=map1.end(); it++){   // present only in nums1
          if(map2.count(it->first)){
            continue;
          }
          else{
            ans[0].push_back(it->first);
          }
        }

        for(auto it=map2.begin(); it!=map2.end(); it++){   // present only in nums2
          if(map1.count(it->first)){
            continue;
          }
          else{
            ans[1].push_back(it->first);
          }
        }
        return ans;
    }
};