#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template<typename T>

class graph {

    public:
        unordered_map<T, list<T>> adjList;             // Adjacency list to represent the graph

        void addEdge(T u, T v, bool dir) {

            // direction = false -> undirected graph
            // direction = true -> directed graph

            // creating an edge from u to v

            adjList[u].push_back(v);                        // Add edge from u to v
            
            if (dir == false) {
                adjList[v].push_back(u);
            }
        }

        void printAdjacencyList() {

            for (auto i : adjList) {
                cout << i.first << " -> ";                  // Print the vertex
                for (auto j : i.second) {
                    cout << j << ", ";                       // Print the connected vertices
                }
                cout << endl;                                // New line after each vertex
            }
        }
};

int main(){

    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    graph<int> g;

    for(int i=0; i<m; i++){
        int u,v;
        cout << "Enter edge " << i + 1 << " (u v): ";
        cin >> u >> v;

        g.addEdge(u, v, false);  // Add edge to the graph
    }

    g.printAdjacencyList();  // Print the adjacency list of the graph
}