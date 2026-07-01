// LC: 2150 m 

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        vector<int>ans;

        for(int num: nums){
          mp[num]++;
        }

        for(auto& [x, count]: mp){

          if(count==1 and mp.count(x+1)==0 and mp.count(x-1)==0){
            ans.push_back(x);
          }
        }
        return ans;
    }
};