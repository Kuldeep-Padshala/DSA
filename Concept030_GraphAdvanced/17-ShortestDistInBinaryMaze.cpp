// LC: 1091 m 

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        // just bfs
        int n = grid.size();
        
        // If start or end is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        // Edge case: single cell
        if (n == 1) return 1;
        
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1; // start counts as length 1
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        // 8 directions
        int dr[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
        
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            int d = dist[r][c];
            
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n 
                    && grid[nr][nc] == 0 
                    && d + 1 < dist[nr][nc]) {
                    
                    dist[nr][nc] = d + 1;
                    
                    if (nr == n-1 && nc == n-1) 
                        return dist[nr][nc]; // reached end
                    
                    q.push({nr, nc});
                }
            }
        }
        
        return -1;
    }
};
