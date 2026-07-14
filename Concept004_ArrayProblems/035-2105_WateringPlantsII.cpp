// LC: 2105 e 

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        
        // Two pointers
        
        int n = plants.size();
        int s = 0;
        int e = n-1;

        int currA = capacityA;
        int currB = capacityB;

        int refill = 0;

        while(s<e){

          if(currA >= plants[s]){
            currA -= plants[s];
          }
          else{
            currA = capacityA - plants[s];
            refill++;
          }

          if(currB >= plants[e]){
            currB -= plants[e];
          }
          else{
            currB = capacityB - plants[e];
            refill++;
          }

          s++;
          e--; 
        }

        if(n % 2 != 0){
          if(max(currA, currB) < plants[n/2]){
            refill++;
          }
        }

        return refill;
    }
};