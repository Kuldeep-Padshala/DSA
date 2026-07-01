// LC: 1224 h 

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        
        int n = nums.size();

        unordered_map<int, int> freq;       // freq of elements
        unordered_map<int, int> mp;         // freq of frequences
        int maxi = 0;                       // max Frequency
        int ans = 0;

        for(int i=0; i<n;i++){

          int num = nums[i];

          if(freq[num] > 0){           // elem ni freq. for example 2 is about to increase
            mp[freq[num]]--;           // atle mp ma 2 par je frequency chhe emathi ek minus
          }

          freq[num]++;                // normal step, elem ni freq increased to 3
          mp[freq[num]]++;     // mp 3 par no freq increase
          maxi = max(maxi, freq[num]);


          int len = i+1;           // atyar sudhi na prefix ni length

          // koi ek elem sivai akha prfix ni freq same:

          // CASE 1: all have -> 1
          // CASE 2: koi ek -> '1'       bija badhai -> maxireq
          // CASE 3: koi ek -> maxireq   bija badhai -> (maxireq-1)

          // case 1. badhai ni one chhe, atle koi ek ne kadhi saki
          if(maxi == 1){
            ans = len;
          }

          // case 2. badhai ni max chhe sivai one with '1'
          else if(maxi * mp[maxi] + 1 == len){      // here,  mp[1] = 1
            ans = len;
          }

          // case 3. badhai ni max-1 chhe sivai one with maxi
          else if((maxi-1) * mp[maxi - 1] + (maxi) == len){   // here, mp[maxi] = 1
            ans = len;
          }
        }
        return ans;
    }
};