// LC: 2614 e 

class Solution {

    bool isPrime(int n){

      if(n<=1) return false;
      if(n==2) return true;

      for(int i=2; i<=sqrt(n); i++){   // imp sqrt(n)
        if(n%i==0) return false;
      }
      return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        
        int n = nums.size();
        int maxi = 0;

        for(int i=0; i<n; i++){

          if(isPrime(nums[i][i])) maxi = max(maxi, nums[i][i]);
          if(isPrime(nums[i][n-i-1])) maxi = max(maxi, nums[i][n-i-1]);
        }

        return maxi;
    }
};