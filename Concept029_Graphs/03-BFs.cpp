// Breadth First Search (BFS) is a fundamental algorithm for traversing or searching tree or graph data structures. 
// It explores all the neighbor nodes at the present depth prior to moving on to nodes at the next depth level.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;    


void prepareAdjacencyList(unordered_map<int, vector<int>>& adjList, vector<pair<int, int>>& edges) {   // disconnected vada case mate

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v); // Add edge from u to v
        adjList[v].push_back(u); // For undirected graph, add edge from v to u
    }
}

void printAdjacencyList(unordered_map<int, vector<int>>& adjList) {
    for (const auto& pair : adjList) {
        cout << pair.first << "-> ";
        for (int neighbor : pair.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}


// void bf(int start, unordered_map<int, vector<int>>& adjList){

//     queue<int> q;
//     unordered_map<int, bool> visited;

//     q.push(start);
//     visited[start] = true;

//     while(!q.empty()) {

//         int node = q.front();
//         q.pop();
//         cout << node << " ";                                     // Process the current node


//         // Visit all adjacent nodes      adjList[node] is a vector of neighbors for the current node 
        
//         for(int neighbor : adjList[node]) {
//             if(!visited[neighbor]) {                                     // not visited

//                 q.push(neighbor);                                        // Add it to the queue
//                 visited[neighbor] = true;                                // Mark it as visited
//             }
//         }
//     }
// }



vector<int> bfs(vector<vector<int>>& adjList)  {

    
    int V = adjList.size();                        // Number of vertices in the graph
    
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



int main() {
    // Example graph represented as an adjacency list
    unordered_map<int, vector<int>> graph;

    // Adding edges to the graph
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5};
    graph[3] = {1};
    graph[4] = {1, 5};
    graph[5] = {2, 4};

    // Print the adjacency list
    cout << "Adjacency List of the Graph:" << endl;
    printAdjacencyList(graph);

    cout << "BFS starting from node 0: ";
    bfs(graph); // Perform BFS starting from node 0

    return 0;
}