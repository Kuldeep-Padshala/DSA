// Depth First Search (DFS) is a fundamental algorithm for traversing or searching tree or graph data structures.
// It starts at the root (or an arbitrary node in the case of a graph) 
// and explores as far as possible along each branch before backtracking.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

void prepareAdjacencyList(unordered_map<int, vector<int>>& adjList, vector<pair<int, int>>& edges) {

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v); // Add edge from u to v
        adjList[v].push_back(u); // For undirected graph, add edge from v to u
    }
}

vector<int> dfs(int node, unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& visited) {

    vector<int> ans;
    stack<int> s;
    s.push(node);
    visited[node] = true;

    while (!s.empty()) {

        int curr = s.top();
        s.pop();
        ans.push_back(curr);

        for (int neighbor : adj[curr]) {

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
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
    // printAdjacencyList(graph);

    unordered_map<int, bool> visited;
    
    cout << "DFS starting from node 0: ";
    vector<int> ans = dfs(0, graph, visited); // Perform DFS starting from node 0

    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}