// LC; 547 m 

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

        if(size[ulp_u] < size[ulp_v]){   // Updating parents depanding on size of its parents, smaller attached to larger
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
    int findCircleNum(vector<vector<int>>& isConnected) {

        // earlier done with dfs/bfs

        // Now using Disjoint set
        int V = isConnected.size();
        DisjointSet ds(V);

        for(int i=0; i<V; i++){
          for(int j=0; j<V; j++){
            if(isConnected[i][j]==1){
              ds.unionBySize(i, j);
            }
          }
        }

        int ans=0;
        for(int i=0; i<V; i++){
          if(ds.parent[i] == i){
            ans++;
          }
        }
        return ans;

    }
};