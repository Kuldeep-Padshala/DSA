// LC:685 h 

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

    bool unionBySize(int u, int v) {

        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);
        if (ulp_u == ulp_v) return false;                      // already in same set

        if(size[ulp_u] < size[ulp_v]){      // Updating parents depanding on size of its parents, smaller attached to larger
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> parent(n+1, 0);
        vector<int> candA, candB;

        // Step 1: detect node with indegree 2
        for (auto &e : edges) {
          
          int u = e[0]; 
          int v = e[1];
          if (parent[v] == 0) {
            parent[v] = u;
          } 
          else {
            candA = {parent[v], v}; // first edge {1,3}
            candB = {u, v};         // second edge {2,3}
            e[1] = 0;               // invalidate candB temporarily
          }
        }

        // Step 2: run DSU
        DisjointSet dsu(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            if(v == 0) continue; // skip invalidated edge
            
            if(!dsu.unionBySize(u, v)) {
              // found a cycle
              if(candA.empty()) return e;  // only cycle, no indegree issue
              return candA;                // indegree + cycle
            }
        }

        // if no cycle, but indegree issue
        return candB;
    }
};