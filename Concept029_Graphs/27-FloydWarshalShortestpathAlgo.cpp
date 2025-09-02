// Floyd Warshal Shortest path algorithm

// Unlike Dijkstra and Bellman Ford algorithms, which find the shortest path from a single source to all other vertices,
// It finds the shortest path from multile sources to multiple destinations.

// It is used to find the shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles).
// The graph is represented as an adjacency matrix, where the value at row i and column j represents the weight of the edge from vertex i to vertex j.
// If there is no edge between two vertices, the weight is represented as infinity (or a very large value).

// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        
        // Code here
        int V = dist.size();
        const int INF = 100000000;
        
        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }
        
        // Step 2: Floyd–Warshall
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < V; j++) {
                    if (dist[k][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};