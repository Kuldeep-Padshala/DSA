// Bridges in Graphs

// So, a bridge (or cut-edge) is an edge in an undirected graph whose removal increases the number of connected components in the graph.
// In other words, if you remove a bridge from the graph, it will disconnect some part of the graph that was previously connected.

// To find all bridges in a graph, we can use a modified Depth-First Search (DFS) algorithm. 
// The key idea is to keep track of the discovery time of each vertex and the lowest discovery time reachable 
// from that vertex using back edges.
// This is commonly known as Tarjan's algorithm for finding bridges.

// If the lowest reachable vertex from a subtree rooted with a vertex v is below v in DFS tree,
// then the edge connecting v to its parent in the DFS tree is a bridge.

// LC: 1192 h 

class Solution {
  int timer = 1;

    void dfs(int node, int parent, vector<int> &visited,
             vector<vector<int>>& adjList, vector<int> &discover,
             vector<int> &lowest, vector<vector<int>> &bridges) {

        visited[node] = 1;
        discover[node] = lowest[node] = timer++;
        //       /
        //      6          6 to 7
        //     / \         7 to 8
        //    7   9        8 to 9, so now 9's(as a node) dfs call, adj is 6, goes to last else cond, update its lowest as 6
        //     \ /         now in 8's(as a node) loop, 9(adj) come back, update lowest of 8 as 6, check for bridge
        //      8          lowest of 9 (6) < disc of 8 (8), it means 9 can be reached via 6 also.
        //      |
        for(auto adj : adjList[node]){
            
          if(adj == parent) continue;  // skip the parent edge
            
          if(!visited[adj]){
            
            // DFS into child
            dfs(adj, node, visited, adjList, discover, lowest, bridges);
                
            // update lowest reachable time, child no lowest time is now also lowest time of node
            lowest[node] = min(lowest[node], lowest[adj]);
                
            // *check for bridge condition
            if(lowest[adj] > discover[node]){      // it means it(adj) cannot been reached from other way than this
              bridges.push_back({adj, node});
            }

            // lowest[adj] <= discover[node]  it means adj can be reached by some other way other than node, so not a bridge
          } 
          else{   // there's no point of bridge here, it is already visited and not a parent, so it then clearly implies that
            
            lowest[node] = min(lowest[node], discover[adj]);           // back edge -> update lowest
          }
        }
    }
public:

    // Tarjan's algorithm, Kosaraju Algo
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adjList(n);
        for (auto &edge : connections) {
          adjList[edge[0]].push_back(edge[1]);
          adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0), discover(n, 0), lowest(n, 0);
        vector<vector<int>> bridges;

        // graph can be disconnected -> run DFS from each component
        for(int node=0; node<n; node++){
          if(!visited[node]) {
            // node par
            dfs(node, -1, visited, adjList, discover, lowest, bridges);
          }
        }

        return bridges;
    }
};