// GfG

class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &visited,
             vector<vector<int>>& adjList, vector<int> &discover,
             vector<int> &lowest, vector<int> &isArticulation) {

        visited[node] = 1;
        discover[node] = lowest[node] = timer++;
        int childCount = 0;  // number of DFS children

        for (auto adj : adjList[node]) {
            
            if (adj == parent) continue;

            if (!visited[adj]) {
                
                dfs(adj, node, visited, adjList, discover, lowest, isArticulation);
                
                // As this comes from the adj, so it is as it is
                lowest[node] = min(lowest[node], lowest[adj]);
                childCount++;

                // case 1: if node is NOT root and no back edge from child
                if (parent != -1 && lowest[adj] >= discover[node]) {
                    isArticulation[node] = 1;
                }
            } 
            else {
                // back edge, so here we will not consider lowest[adj], we are not supposed to rely
                // on someone who may be articulation point, so we will not reach here
                // in lowest[adj] time without it
                lowest[node] = min(lowest[node], discover[adj]);
            }
        }

        // case 2: if root and has more than 1 child → articulation
        if (parent == -1 && childCount > 1) {
            isArticulation[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adjList(n);
        for (auto &edge : connections) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0), discover(n, 0), lowest(n, 0), isArticulation(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1, visited, adjList, discover, lowest, isArticulation);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (isArticulation[i]) result.push_back(i);
        }
        if (result.empty()) return {-1}; // convention in some problems
        return result;
    }
};
