vector<int> dfs1(unordered_map<int, vector<int>>& adjList) {    // with stack

    int start = 0; 

    stack<int> s;
    s.push(start);
    
    unordered_map<int, bool> visited;
    visited[start] = true;
    

    vector<int> ans;

    while (!s.empty()) {

        int curr = s.top();
        s.pop();
        ans.push_back(curr);

        for(int it : adjList[curr]){

          if(!visited[it]) {
            visited[it] = true;
            s.push(it);
          }
        }
    }

    return ans;
}


void dfs2(int node, unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& ans){

    visited[node] = true;
    ans.push_back(node);

    for(int it : adjList[node]){

        if(!visited[it]){
            dfs2(node, adjList, visited, ans);
        }
    }

}
// TC: O(n) + O(2*E)
// SC: O(n)