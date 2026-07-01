// LC: 2488 h 

/* nums:    [  7,  1,  3,  4,  2,  5,  6 ], k = 4
    bal:     [  1,  0, -1, -1, -2, -1,  0 ]
             |<- cnt ->| |<---- ans ---->|

    Trace:
    ans:                1.  0.  1.  2+1                
                       -1  [4]
                               -1  [4,2,5]
                                    0  [3,4,2,5,6]
                                    0  [7,1,3,4,2,5,6]
                                   -1  [4,2,5,6]
                               
    cnt (prefix frequencies):
      1: 1 (idx 0)
      0: 2 (idx -1, 1)
     -1: 1 (idx 2)

    Example: 
      Value 4 at (idx 3) has bal -> -1
      Find  3 at (idx 2) has bal -> -1 
      Subarray: idx 2+1 (3) to idx 3 => balance difference: -1 - (-1) == 0
        
    Logic:
      greater - smaller == 0 or 1
      => curBalance - x == 0 or 1
      => x == curBalance or x == curBalance - 1
*/


class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        unordered_map<int, int> mp; // prefix
        mp[0] = 1;                  // can be think as the prefix on index -1
        
        bool includeK = false;
        int balance = 0; 
        
        int ans = 0;

        for(int i=0; i<n; i++){
            
            if(nums[i] < k){
              balance--;
            }
            else if(nums[i] > k){
              balance++;
            }
            else{             // num[i] == k
              includeK = true;
            } 
            
            if(includeK){

              // find x in prefix hashmap 
              // greater - smaller == 0 or 1
              // => prefix[i] - prefix[x] == 0 or 1
              // => curBalance - prefix[x] == 0 or curBalance - prefix[x] == 1
              // => prefix[x] == curBalance or prefix[x] == curBalance - 1
              ans += mp[balance] + mp[balance-1]; 
            }
            else{
              mp[balance]++;
            }
        }
        return ans; 
    }
};