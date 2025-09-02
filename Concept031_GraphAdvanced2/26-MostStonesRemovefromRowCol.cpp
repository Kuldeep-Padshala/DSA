// LC: m947 m 

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
    int removeStones(vector<vector<int>>& stones) {
        
        // So here we can remove nodes from the components except one from each
        // If c num of components, then from all nodes, c nodes(from each component) sould remain at last
        // So ans = (num of nodes) - (total num of components)

        // "Connecting"  -> DisjointSet DS
        
        int n=stones.size();
        int rows=0, cols=0;
        for(auto it: stones){
          rows = max(rows, it[0]);
          cols = max(cols, it[1]);
        }
        // 0  1  2  3  4
      // 0       1
      // 1    1
      // 2 
      // 3    1  1
      // 4 1           1  

        DisjointSet ds(rows+cols+1);
        unordered_map<int,int> stoneNodes;

        for(auto it: stones){
          int row = it[0];
          int col = it[1] + rows + 1;
          ds.unionBySize(row, col);       // this whole row is connecd with the column
          stoneNodes[row] = 1;
          stoneNodes[col] = 1;
        }

        int components=0;
        for(auto it: stoneNodes){
          if(ds.findUltParent(it.first) == it.first){
            components++;
          }
        }
        return n - components; 
    }
};