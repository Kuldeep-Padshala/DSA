// GfG
// LC: 305 h 

// User function Template for C++
class DisjointSet {
    vector<int> parent, size;
public:

    DisjointSet(int n) {               // Constructor

        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;  // initially, every node is its own parent
            size[i] = 1;
        }
    }

    int findUltParent(int node) {

        if(node == parent[node])   return node;

        // path compression
        return parent[node] = findUltParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);
        if (ulp_u == ulp_v) return;                      // already in same set

        if(size[ulp_u] < size[ulp_v]){                // Updating parents depanding on size of its parents, smaller attached to larger
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        // code here
        DisjointSet ds(n * m);
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int cnt = 0;             // number of islands
        vector<int> ans;
        
        // Directions: up, right, down, left
        int del_row[4] = {-1, 0, 1, 0};
        int del_col[4] = {0, 1, 0, -1};
        
        for(auto &op : operators) {
            int row = op[0];
            int col = op[1];
            
            // If already land, push current count
            if(visited[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            
            // Mark as land
            visited[row][col] = 1;
            cnt++;                   // pela count vadharvano
            
            // Check 4 neighbors
            for(int i=0; i<4; i++) {
                
                int nrow = row + del_row[i];
                int ncol = col + del_col[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {       // if valid
                    
                    if(visited[nrow][ncol] == 1) {
                        
                        int node = row * m + col;
                        int adjNode = nrow * m + ncol;
                        // If different components → merge
                        if(ds.findUltParent(node) != ds.findUltParent(adjNode)) { // if not already connected to it
                            cnt--;
                            // ds.unionBySize(node, adjNode);
                            ds.unionBySize(adjNode, node);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
        
    }
};
