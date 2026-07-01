// LC: 1248 m 

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int cnt = 0;
        int ans = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int num: nums){
          
          if(num % 2 != 0){
            cnt++;
          }

          if(mp.find(cnt-k) != mp.end()){
            ans += mp[cnt-k];
          }
          mp[cnt]++;
        }
        
        return ans;
    }
};