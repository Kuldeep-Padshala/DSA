// LC: 974 m 

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        // HashMaps + PrefixSum
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefix_sum = 0;
        int cnt = 0;

        for(int i=0; i<n; i++){
          
          prefix_sum += nums[i];
          int remainder = prefix_sum % k;

          if(remainder < 0){
            remainder += k;
          }

          if(mp.find(remainder) != mp.end()){
            cnt += mp[remainder];
            mp[remainder]++;
          } 
          else{
            mp[remainder] = 1;
          }
        }
        return cnt;

        
        // without map
        // int n = nums.size();
        // vector<int> sums(k, 0);
        // sums[0]++;

        // int cnt = 0;
        // int currSum = 0;

        // for(int i=0; i<n; i++){
          
        //   currSum = (currSum + nums[i]%k + k)%k;
        //   cnt += sums[currSum];
        //   sums[currSum]++;
        // }
        // return cnt;
    }
};