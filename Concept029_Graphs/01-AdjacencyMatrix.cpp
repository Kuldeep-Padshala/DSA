// Implementation of an adjacency matrix for a graph in C++

#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:

    vector<vector<int>> adjMatrix; // Adjacency matrix to represent the graph
    int numVertices; // Number of vertices in the graph
    
public:
    // Constructor to initialize the graph with a given number of vertices      
    Graph(int vertices) : numVertices(vertices) {
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0)); // Initialize the matrix with zeros
    }
    // Function to add an edge between two vertices
    void addEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            adjMatrix[src][dest] = 1; // Set the edge from src to dest
            // For undirected graph, uncomment the next line
            // adjMatrix[dest][src] = 1; // Set the edge from dest to src
        } else {
            cout << "Invalid vertices!" << endl;
        }
    }
    // Function to display the adjacency matrix
    void display() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    // Function to check if there is an edge between two vertices
    bool isEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            return adjMatrix[src][dest] == 1; // Return true if there is an edge
        } else {
            cout << "Invalid vertices!" << endl;
            return false;
        }
    }
    // Function to get the number of vertices in the graph
    int getNumVertices() const {
        return numVertices; // Return the number of vertices
    }
    // Function to get the adjacency matrix
    vector<vector<int>> getAdjMatrix() const {
        return adjMatrix; // Return the adjacency matrix
    }
    // Destructor
    ~Graph() {
        // No dynamic memory allocation, so nothing to clean up
    }
    // Function to clear the graph
    void clear() {  
        adjMatrix.clear(); // Clear the adjacency matrix
        numVertices = 0; // Reset the number of vertices
    }
};

int main() {
    
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1); // Add an edge from vertex 0 to vertex 1
    g.addEdge(0, 4); // Add an edge from vertex 0 to vertex 4
    g.addEdge(1, 2); // Add an edge from vertex 1 to vertex 2
    g.addEdge(1, 3); // Add an edge from vertex 1 to vertex 3
    g.addEdge(1, 4); // Add an edge from vertex 1 to vertex 4
    g.addEdge(2, 3); // Add an edge from vertex 2 to vertex 3
    g.addEdge(3, 4); // Add an edge from vertex 3 to vertex 4

    g.display(); // Display the adjacency matrix

    cout << "Is there an edge between 0 and 1? " << (g.isEdge(0, 1) ? "Yes" : "No") << endl;
    cout << "Is there an edge between 2 and 4? " << (g.isEdge(2, 4) ? "Yes" : "No") << endl;

    return 0; // Exit the program
}