// LC: 1137 e 

class Solution {
public:
    int tribonacci(int n) {
        
        // ------------------ BottomUp Space Optimization  ---------------------
        int zero = 0;
        if(n==0) return 0;
        int one = 1;
        if(n==1) return 1;
        int two = 1;
        if(n==2) return 1;

        for(int i=3; i<=n; i++) {
          int curr = zero + one + two;
          zero = one; one = two; two = curr;
        }
        return two;
    }
};