class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size();
        vector<int> diff(n+1,0);

        // Build difference array
        for(auto &shift : shifts){
            
          int s = shift[0];
          int e = shift[1];
          int d = shift[2];

          int val = (d == 1 ? 1 : -1);

          diff[s] += val;
          if(e+1 < n) diff[e+1] -= val;
          
        }

        // Prefix sum + apply shift
        
        int curr = 0;
        for(int i=0; i<n; i++){

          curr += diff[i];

          // normalize shift into [0,25]
          int shift = ((curr%26 )+ 26) % 26;

          s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};