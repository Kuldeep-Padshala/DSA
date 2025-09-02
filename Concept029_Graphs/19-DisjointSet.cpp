// Disjoint Set  (Dynamic graphs, Connecting nodes, initially individual nodes)

// So disjoint set is a data structure that keeps track of a partition of a set into disjoint (non-overlapping) subsets.
// It tells wether two elements belongs to the same component or not.
// It supports two main operations: find and union.

// Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
// Union: Join two subsets into a single subset.
// It is also known as union-find data structure or merge-find set.

// Union can be further classified into two types:
// 1. Union by rank: Attach the smaller tree under the root of the larger tree
// 2. Union by size: Attach the smaller tree under the root of the larger tree

// Union By Rank and Path Compression
// Union (u, v): 
// Steps:
// 1) Find the ultimate parent of the node pu, pv (in vector parent)    
// 2) Find the rank of pu, pv (in vector rank)
// 3) Connect smaller rank tree under larger rank tree   (in order to maintain the height balanced)
// 4) If ranks are same, then make one as root and increment its rank by one

// Path Compression in Find:
// 1) Find the ultimate parent of the node
// 2) While returning back, make the parent of each node as the ultimate parent

// TC: O(4*alpha) ~= O(1)  SC: O(N) for parent and rank array




#include <bits/stdc++.h>    // for codechef, it includes all standard headers
using namespace std;


class DisjointSet {
    vector<int> parent, rank;
public:

    DisjointSet(int n) {               // Constructor

        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i = 0; i <= n; i++){
            parent[i] = i;  // initially, every node is its own parent
        }
    }

    int findUltParent(int node) {

        if(node == parent[node]) return node;

        // *path compression*
        return parent[node] = findUltParent(parent[node]);
    }

    void unionByRank(int u, int v) {

        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);
        if (ulp_u == ulp_v) return;                      // already in same component, ignore

        if (rank[ulp_u] < rank[ulp_v]) {                // Updating parents depanding on ranks of its parents
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {                                          // if same rank of ultParents
            parent[ulp_v] = ulp_u;      // we can also converse it
            rank[ulp_u]++; // increase rank only when equal
        }
    }
};

int main() {
    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // check if 3 and 7 belong to same component
    if(ds.findUltParent(3) == ds.findUltParent(7)){
        cout << "Same\n";
    }
    else{
        cout << "Not same\n";
    }

    ds.unionByRank(3, 7);

    if(ds.findUltParent(3) == ds.findUltParent(7)){
        cout << "Same\n";
    }
    else{
        cout << "Not same\n";
    }

    return 0;
}

