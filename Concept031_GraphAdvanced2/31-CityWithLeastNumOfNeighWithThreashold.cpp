// LC: 1334 m   Find the City With the Smallest Number of Neighbors at a Threshold Distance 

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // using floyd warshal, TC:O(n*n*n)
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        for(int i=0; i<n; i++) dist[i][i] = 0;

        for(auto &e : edges){
          int u = e[0], v = e[1], wt = e[2];
          dist[u][v] = wt;
          dist[v][u] = wt;
        }
        
        // Floyd–Warshall
        for(int k = 0; k < n; k++){
          for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
              if(dist[i][k] + dist[k][j] < dist[i][j]){
                dist[i][j] = dist[i][k] + dist[k][j];
              }
            }
          }
        }
        
        int ans = -1, minReach = INT_MAX;
        for(int city=0; city<n; city++){
          
          int reach = 0;
          for(int adj_city = 0; adj_city < n; adj_city++){
            if (city != adj_city && dist[city][adj_city] <= distanceThreshold) reach++;
          }
          if(reach <= minReach) { // tie → larger index wins
            minReach = reach;
            ans = city;
          }
        }
        return ans;
    }
};