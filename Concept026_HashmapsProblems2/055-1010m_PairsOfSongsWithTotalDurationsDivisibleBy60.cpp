// LC: 1010 m 

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        // unordered_map<int, int> mp;
        // int ans = 0;
        // // mp[0] = 1;

        // for(int t: time){
          
        //   t = t%60;

        //   // ans += mp[(60-t)%60];
        //   // mp[t]++;

        //   if(t==0){
        //     ans += mp[0];
        //     mp[0]++;
        //     continue;
        //   }

        //   if(mp.count(60-t) != 0){
        //     ans += mp[60-t];
        //   }
        //   mp[t]++;
        // }
        // return ans;


        vector<int> mp(60, 0);
        int ans = 0;

        for(int t : time) {
          
          t = t % 60;

          ans += mp[(60-t)%60];
          mp[t]++;

        }

        return ans;
    }
};