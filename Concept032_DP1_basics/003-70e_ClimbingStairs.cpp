// LC: 70 e 

class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
        return 1;
        if(n==2)
        return 2;

        // return climbStairs(n-1)+climbStairs(n-2);   time limit exceeded

        int first = 1, second = 2, result; 
        for(int i = 3; i <= n; i++){ 
          result = first + second; 
          first = second; 
          second = result; 
          } 
          
          return second;
    }
};