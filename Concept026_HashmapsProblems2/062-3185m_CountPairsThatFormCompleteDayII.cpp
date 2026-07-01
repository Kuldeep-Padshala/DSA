// LC: 3185 m 

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        
        unordered_map<int, int> mp;
        long long count = 0;

        for(int hour: hours){
          
          int rem = hour % 24;
          int complement = (24-rem)%24;

          if(mp.find(complement) != mp.end()){
            count += mp[complement];
          }
          mp[rem]++;
        }

        return count;

    }
};