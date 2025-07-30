// LC: 229 m

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans;
        double k = nums.size()/3.0;
        unordered_map<int,int> freq;

        for(int num : nums){
          freq[num]++;
        }
        for(auto it=freq.begin(); it!=freq.end(); it++){
          if(it->second > k){
            ans.push_back(it->first);
          }
        }
        return ans;
    }
};