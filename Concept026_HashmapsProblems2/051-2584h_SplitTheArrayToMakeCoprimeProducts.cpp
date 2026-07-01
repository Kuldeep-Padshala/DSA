// LC: 2548 h 

class Solution {
public:

    // map of prime factors with count
    unordered_map<int,int> getFactors(int x){
        
      unordered_map<int,int> freq;
      int f=2;
      
      while(x>1 && f*f<=x){
        while(x%f==0){
          
          freq[f]++;
          x/=f;
        }
        f++;
      }
      
      if(x!=1)    freq[x]=1;        // itself prime
      return freq;
    }

    
    int findValidSplit(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> mp1;

        // for(auto it = factors.begin(); it!=factors.end(); it++) cout << it->first << " -> " << it->second << endl;
 
        for(int num: nums){

          auto factors = getFactors(num);

          for(auto& [prime,cnt]:factors){
            mp1[prime] += cnt;
          }
        }

        // No prime number should exist on both the left and the right sides at the same time.

        auto mp2 = mp1;     // the temp map 
        int dirty=0;        // dirty means the number of prime factors having exponentitaion!=0 and !=the initial config.
        // tracks how many unique prime factors currently exist on both sides
        // If dirty == 0, it means no primes are shared

        for(int i=0; i<n-1; i++){

          auto factors = getFactors(nums[i]);
            
          for(auto& [prime,cnt]: factors){

            if(mp2[prime] == mp1[prime] && cnt != mp2[prime])   dirty++;   // p^(x-a) here x-a now becomes non 0
            if(mp2[prime] != mp1[prime] && cnt == mp2[prime])   dirty--;    // this prime number was dirty before
            mp2[prime] -= cnt;
          }
            
          if(dirty==0)   return i;
        }
        return -1;
    }
};