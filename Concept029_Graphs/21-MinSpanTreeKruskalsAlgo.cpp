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
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        // code here
        
        // Sort edges by weight (edges[i] = {u, v, wt})
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        DisjointSet ds(V);
        int weight = 0;
        vector<vector<int>> mstEdges;   // To store the edges of MST
        
        // Process edges in increasing weight
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            // If u and v are not in same component, include this edge
            if(ds.findUltParent(u) != ds.findUltParent(v)) {
                
                weight += wt;
                mstEdges.push_back({u, v, wt});   // store the edge in MST
                ds.unionBySize(u, v);
            }
        }
        
        return weight;
        
    }
};