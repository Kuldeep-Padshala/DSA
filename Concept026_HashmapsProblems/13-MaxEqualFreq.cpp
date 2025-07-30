// LC: 1224 h

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        
        unordered_map<int, int> count;       // count of elements
        unordered_map<int, int> freq_count;   // count of frequences
        int maxF = 0;
        int ans = 0;

        for(int i=0; i<nums.size();i++){

          int num = nums[i];

          if(count[num] > 0){           // elem ni freq. for example 2 is about to increase
            freq_count[ count[num] ]--;   // atle freq_count ma 2 par je frequency chhe emathi ek minus
          }

          count[num]++;                // normal step, elem ni freq increased to 3
          freq_count[count[num]]++;     // freq_count 3 par no count increase
          maxF = max(maxF, count[num]);


          int len = i+1;           // atyar sudhi na prefix ni length

          // koi ek elem sivai akha prfix ni freq same:

          // CASE 1: all have -> 1
          // CASE 2: koi ek -> '1'       bija badhai -> MaxFreq
          // CASE 3: koi ek -> maxFreq   bija badhai -> (MaxFreq-1)

          // case 1. badhai ni one chhe, atle koi ek ne kadhi saki
          if(maxF == 1){
            ans = len;
          }

          // case 2. badhai ni max chhe sivai one with '1'
          else if(maxF * freq_count[maxF] + 1 == len){      // here,  freq_count[1] = 1
            ans = len;
          }

          // case 3. badhai ni max-1 chhe sivai one with maxF
          else if((maxF-1) * freq_count[maxF - 1] + (maxF) == len){   // here, freq_count[maxF] = 1
            ans = len;
          }
        }
        return ans;
    }
};