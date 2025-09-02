// LC: 1462 m 

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        // int n = prerequisites.size();
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto &e : prerequisites){

          // Ques id diff
          int u = e[0];
          int v = e[1];
          
          adjList[u].push_back(v);
          inDegree[v]++;
        }

        // zero vada push
        queue<int> q;
        for(int i=0; i<numCourses; i++){
          if(inDegree[i] == 0){
            q.push(i);
          }
        }

        // prerequisite set for each node

        vector <unordered_set<int>> prereq(numCourses);
        // vector<bitset<100>> prereq(n);

        while(!q.empty()) {
          
          int node = q.front(); 
          q.pop();
            
          for(int adj : adjList[node]){

            inDegree[adj]--;
            if(inDegree[adj] == 0){
              q.push(adj);
            }

            // everything that is prerequisite of node becomes prereq of adj
            for(int pre : prereq[node]){
              prereq[adj].insert(pre);
            }
            // u itself is also a prereq of v
            prereq[adj].insert(node);

            // prereq[adj] |= prereq[node];  // inherit all prerequisites of u
            // prereq[adj][node] = 1;        // u is a prerequisite of v
          }
        }

        // answer queries
        vector<bool> ans;
        // ans.reserve(queries.size());
        for(auto &q : queries) {
          if(prereq[q[1]].count(q[0])){
            ans.push_back(true);
          }
          else{
            ans.push_back(false);
          }
        }
        return ans;
    }
};