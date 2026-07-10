// LC: 56 m 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // sorting and greedy
        
        int n = intervals.size();
        sort(begin(intervals), end(intervals));    // start time thi sort

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1; i<n; i++){

          vector<int>& prev = ans.back();
          vector<int> curr = intervals[i];

          if(prev[1] < curr[0]){   // khali chhe, athva overlap no thata hoi
            ans.push_back(curr);
          }
          else{
            prev[1] = max(prev[1], curr[1]);
          }
        }
        return ans;
    }
};