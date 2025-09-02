// Kosaraju's Algorithm to find Strongly Connected Components (SCC) in a directed graph

// A directed graph is strongly connected if there is a path from each vertex in the graph to every other vertex.
// A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.
// Kosaraju's algorithm is a linear time algorithm to find all SCCs in a directed graph.
// TC: O(V + E)  SC: O(V) for stack, visited array, transpose graph

// Steps:
// 1) Find the finishing order of nodes in a stack using DFS, push to stack after all its adjacent nodes are visited (topological sort)
// 2) Transpose the graph (reverse all edges)
// 3) Pop nodes from stack and do DFS on transposed graph, each DFS call will give one SCC

//Position this line where user code will be pasted.
class Solution {
    
    void dfs1(int node, vector<int> &visited, stack<int> &st, vector<vector<int>> &adj) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs1(it, visited, st, adj);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<int> &visited, vector<vector<int>> &adjT, vector<int> &currentSCC) {
        visited[node] = 1;
        currentSCC.push_back(node);
        for (auto it : adjT[node]) {
            if (!visited[it]) {
                dfs2(it, visited, adjT);
            }
        }
    }
    
  public:
    int kosaraju(vector<vector<int>> &adj) {
        
        int V = adj.size();
        vector<int> visited(V, 0);
        stack<int> st;

        // Step 1: Order vertices by finish time in DFS
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i, visited, st, adj);
            }
        }

        // Step 2: Transpose graph
        vector<vector<int>> adjT(V);
        for (int node = 0; node < V; node++) {
            
            visited[node] = 0;    // reseting it for further use
            for (auto neigh : adj[node]) {
                adjT[neigh].push_back(node);
            }
        }

        // Step 3: DFS in the order of stack on transposed graph
        int ans = 0;
        vector<vecotr<int>> scc;
        while (!st.empty()) {
            
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                ans++;
                scc.push_back({});
                dfs2(node, visited, adjT, scc.back());
            }
        }
        return ans;
    }
};
