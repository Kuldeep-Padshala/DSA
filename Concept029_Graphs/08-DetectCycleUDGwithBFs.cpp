class Solution {
    
void prepareAdjacencyList(vector<vector<int>>& adjList, vector<vector<int>>& edges) {   // disconnected vada case mate

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v); // Add edge from u to v
        adjList[v].push_back(u); // For undirected graph, add edge from v to u
    }
}
    
    bool detectCycle(int start, vector<vector<int>>& adjList, vector<bool>& visited){
        
        visited[start] = true;
        queue<pair<int,int>> q;
        //      node  prev
        q.push({start, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adj_node: adjList[node]){
                
                if(!visited[adj_node]){
                    visited[adj_node] = true;
                    q.push({adj_node, node});
                }
                else if(adj_node != parent){       // visited but not parent, cycle present
                    return true;
                }
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
                if (detectCycle(i, adjList, visited)) return true;
            }
        }
        return false;
    }
};