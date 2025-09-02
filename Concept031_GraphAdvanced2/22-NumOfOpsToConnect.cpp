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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        // Earlier done with dfs/bfs

        // Now with DisjointSet
        // If not enough edges to ever connect all nodes
        
        if(connections.size() < n-1) return -1;    // if no extra edges to remove

        DisjointSet ds(n);

        // Union all edges
        for(auto &conn : connections) {
            int u = conn[0];
            int v = conn[1];

            // if(ds.parent[u] == ds.parent[v]){ // This way also we can find extra edges and then say it is possible or not
            //   extraEdge++;
            //   continue;
            // }
            ds.unionBySize(u, v);
        }

        // Count unique components
        int ans = 0;
        for(int i = 0; i < n; i++) {
          if(ds.parent[i] == i) ans++;
        }

        // To connect components, we need (components - 1) cables
        return ans - 1;
    }
};