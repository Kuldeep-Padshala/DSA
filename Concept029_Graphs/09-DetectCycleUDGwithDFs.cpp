class Solution {
    
    void prepareAdjacencyList(vector<vector<int>>& adjList, vector<vector<int>>& edges) {   // disconnected vada case mate

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v); // Add edge from u to v
        adjList[v].push_back(u); // For undirected graph, add edge from v to u
    }
}
    
    bool dfs(int node, int parent, vector<vector<int>>& adjList, vector<bool>& visited){
        
        visited[node] = true;
        
        for(int adj_node: adjList[node]){
            if(!visited[adj_node]){
                if(dfs(adj_node, node, adjList, visited)){
                    return true;
                }
            }
            else if(adj_node != parent){
                return true;
            }
        }
        return false;
    }
    
    
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // Code here
        vector<vector<int>> adjList(V);
        prepareAdjacencyList(adjList, edges);
        
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adjList, visited)) return true;
            }
        }
        return false;
    }
};