#include<iostream>
using namespace std;

int main(){

    int n, m;
    cout << "Nodes: "; 
    cin >> n;
    cout << endl << "Edges: ";
    cin >> m;
    cout << endl;

    vector<int> adj;
    
    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);    // not to do for directed graph
    }
    return 0;
}