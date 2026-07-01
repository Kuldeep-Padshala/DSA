// LC: 3159 m 

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        
        int n = nums.size();

        vector<int> count, ans;
        for(int i=0; i<n; i++){
          if(nums[i] == x ){
            count.push_back(i);
          }
        }

        for(int q : queries){
          
          if(q > count.size()) ans.push_back(-1);
          else ans.push_back(count[q-1]);
        }
        return ans;

        // unordered_map<int, int> mp;

        // int occ=1;

        // for(int i=0; i<n; i++){
        //   if(nums[i] != x) continue;

        //   mp[occ++] = i;
        // }

        // vector<int> ans;
        // for(int q: queries){

        //   if(mp.find(q) == mp.end()){
        //     ans.push_back(-1);
        //   }
        //   else{
        //     ans.push_back(mp[q]);
        //   }
        // }
        // return ans;
    }
};