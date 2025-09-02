// Problem: Find Minimum Spanning Tree using Prim's Algorithm

// Minimum Spanning Tree (MST) is a subset of edges in a connected, undirected and weighted graph such that
// 1. All vertices are included in the subset
// 2. There is no cycle in the subset
// 3. The sum of weights of edges in the subset is minimum
// 4. If V is the number of vertices, then the subset must have V-1 edges

// Prim's Algorithm is a greedy algorithm that finds the MST by starting from an arbitrary node and
// adding the smallest edge that connects a vertex in the MST to a vertex outside the MST until all vertices are included.
// TC: O(E log V)  SC: O(V) for visited array and priority queue

class Solution {
public:
    pair<int, vector<vector<int>>> spanningTree(int V, vector<vector<int>>& edges) {
        
        // adjacency list: {adjNode, weight}

        vector<vector<pair<int,int>>> adjList(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        //                  wt, {node, parent}             tracking parent cause we want MST
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
        pq.push({0, {0, -1}});

        vector<bool> visited(V, false);
        int weight = 0;                                       // sum of all edges of MST
        vector<vector<int>> mstEdges;   // store {u, v, wt}


        while (!pq.empty()) {

            auto it = pq.top(); 
            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            pq.pop();

            if(visited[node]) continue;

            // include this node in MST
            visited[node] = true;
            weight += wt;
            if(parent != -1) {
                mstEdges.push_back({parent, node, wt});
            }

            for (auto neigh : adjList[node]) {

                int neigh_node = neigh.first;
                int edge_wt = neigh.second;
                if (!visited[neigh_node]) {
                    pq.push({edge_wt, {neigh_node, node}});
                }
            }
        }

        return {weight, mstEdges};
    }
};
