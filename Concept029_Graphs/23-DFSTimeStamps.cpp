// LCC: 2360 h 

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        
        // Aproach 1: TimeStamp + DFS
        // SCC Kosaraju's Algo

        // Aproach 1

        // Each node has only one out edge at max
        int n = edges.size();
        vector<int> visitTime(n, 0);
        int timestamp = 1, ans = -1;

        for (int i=0; i<n; i++) {
          
          if(visitTime[i]) continue;  // already visited

            int startTime = timestamp;
            int curr = i;

            // 
            while(curr != -1 && !visitTime[curr]) {
              visitTime[curr] = timestamp;
              timestamp++;
              // next
              curr = edges[curr];
            }

            // If we're in a cycle starting in this traversal
            if(curr != -1 && visitTime[curr] >= startTime) {            // it was visited in this exploration (cycle) only.
              //         total time of cycle - time at start point 
              ans = max(ans, timestamp - visitTime[curr]);
            }
        }

        return ans;
    }
};