// Breadth First Search (BFS) is a fundamental algorithm for traversing or searching tree or graph data structures. 
// It explores all the neighbor nodes at the present depth prior to moving on to nodes at the next depth level.

vector<int> bfs(vector<vector<int>>& adjList)  {

    
    // int V = adjList.size();                        // Number of vertices in the graph
    
    queue<int> q;  
    unordered_map<int, bool> visited;
    
    int start = 0;                                 // Starting node
    visited[start] = true;    // pelo node visited
    q.push(start);

    vector<int> ans;

    while (!q.empty()) {
      
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        // Get all adjacent vertices of the dequeued vertex curr,  
        // If an adjacent not visited, mark it visited and enqueue it

        for (int x : adjList[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return ans;
}