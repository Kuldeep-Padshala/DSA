// LC: 2079 m 

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        
        int n = plants.size();
        int curr = capacity;
        int steps = 0;

        for(int i=0; i<n; i++){

          if(curr>=plants[i]){
            curr -= plants[i];
          }
          else{
            curr = capacity - plants[i];
            steps += 2*(i);
          }
          steps++;          
        }
        return steps;
    }
};