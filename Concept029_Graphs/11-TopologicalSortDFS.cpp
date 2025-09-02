// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices 
// such that for every directed edge u -> v, vertex u comes before v in the ordering.

class Solution {
    void dfsTopo(int node, vector<bool>& visited, stack<int>& st, vector<vector<int>>& adjList){
        
        visited[node] = true;
        for(auto& adj : adjList[node]){
            if(!visited[adj]){
                dfsTopo(adj, visited, st, adjList);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adjList(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1]
            adjList[u].push_back(v);  // directed edge u->v
        }
        
        // code here
        vector<bool> visited(V, false);
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfsTopo(i, visited, st, adjList);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            // cout<<st.top()<<endl;
            st.pop();
        }
        return ans;
        
    }
};