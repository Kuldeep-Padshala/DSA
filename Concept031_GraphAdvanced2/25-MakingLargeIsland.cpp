// LC:827 h

class DisjointSet {
public:
    vector<int> parent, size;

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

        if(size[ulp_u] < size[ulp_v]){    // Updating parents depanding on size of its parents, smaller attached to larger
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
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        DisjointSet ds(n * n);

        // Step 1: Union all 1's
        int del_row[4] = {-1, 0, 1, 0};
        int del_col[4] = {0, 1, 0, -1};

        for(int row=0; row<n; row++) {
          for(int col=0; col<n; col++) {
                
            if(grid[row][col] == 1) {
                    
              int node = row * n + col;
                    
              for(int i=0; i<4; i++) {
                int nrow = row + del_row[i];
                int ncol = col + del_col[i];
                        
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                  int adjNode = nrow * n + ncol;
                  ds.unionBySize(node, adjNode);
                }
              }
            }
          }
        }
        
        int maxSize = 0;
        bool hasZero = false;
        // Step 2: Try flipping each 0
        for(int row=0; row<n; row++) {
          for(int col=0; col<n; col++) {
                
            if(grid[row][col] == 0) {
              hasZero = true;
              unordered_set<int> uniqueParents;
              int currSize = 1; // flipping this 0
                    
              for(int i=0; i<4; i++) {
                int nrow = row + del_row[i];
                int ncol = col + del_col[i];
                        
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                            
                  int parent = ds.findUltParent(nrow * n + ncol);
                  if(!uniqueParents.count(parent)) {   // if its a different component or not
                    uniqueParents.insert(parent);
                    currSize += ds.size[parent];
                  }
                }
              }
              maxSize = max(maxSize, currSize);
            }
          }
        }

        // Step 3: Also consider case where grid is already all 1s
        if(!hasZero){
          maxSize = max(maxSize, n*n);
        }

        return maxSize;
    }
};