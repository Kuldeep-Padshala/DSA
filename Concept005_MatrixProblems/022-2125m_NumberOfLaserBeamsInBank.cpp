// LC: 2125 m 

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int ans=0, prev=0;

        for(auto& row: bank){

          int devices = count(row.begin(), row.end(), '1');
          
          if(devices>0){
            ans += devices * prev;
            prev = devices;

            // exchange use kari ne
            // ans += exchange(prev,devices) * devices;
          }
        }
        return ans;
    }
};