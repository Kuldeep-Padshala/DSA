#include <bits/stdc++.h>    // for codechef, it includes all standard headers
using namespace std;


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

int main() {
    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // check if 3 and 7 belong to same component
    if(ds.findUltParent(3) == ds.findUltParent(7)){
        cout << "Same\n";
    }
    else{
        cout << "Not same\n";
    }

    ds.unionBySize(3, 7);

    if(ds.findUltParent(3) == ds.findUltParent(7)){
        cout << "Same\n";
    }
    else{
        cout << "Not same\n";
    }

    return 0;
}

