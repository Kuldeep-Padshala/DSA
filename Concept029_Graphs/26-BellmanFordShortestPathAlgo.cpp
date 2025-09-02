// Bellman Ford's Algorithm

// It is used to find the shortest path from a source vertex to all other vertices in a weighted graph.
// We can also find this using Dijksta's Algorithm, but it doesn't work for graphs with NEGATIVE weight edges.

// Bellman Ford's Algorithm can handle graphs with negative weight edges, but it cannot handle graphs with negative weight cycles.
// If there is a negative weight cycle in the graph, then the algorithm will detect it and report that no solution exists.
// So indirectly it can be used to detect negative weight cycles also.
// TC: O(V * E)  SC: O(V) for distance array

// Note: It only works for directed graphs.
// If you want to use it for undirected graphs, you need to convert it to directed graph 
// by replacing each undirected edge with two directed edges of same weight in both directions.

// Steps:
// 1) Initialize the distance to the source vertex to 0 and all other vertices to infinity.
// 2) Relax all edges V-1 times (where V is the number of vertices in the graph).
//      if    dist[u] + wt < dist[v]
//      then  dist[v] = dist[u] + wt   (n-1) times
// 3) Check for negative weight cycles by trying to relax the edges one more time. If we can relax any edge, 
//    then there is a negative weight cycle in the graph.
// Note: Relaxing an edge means updating the distance to the destination vertex if the distance to the source vertex
//       plus the weight of the edge is less than the current distance to the destination vertex.

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        // Code here
        vector<int> dist(V, 1e8);   // initially infinity
        dist[src] = 0;
        
        // Step 2: Relax all edges V-1 times
        for (int i = 1; i <= V-1; i++) {
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Step 3: Check for negative cycle
        // For nth time relaxation is already done. if still it gets updated, there present the negative cycle
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1}; // Negative weight cycle detected
            }
        }
        
        return dist;
    }
};

