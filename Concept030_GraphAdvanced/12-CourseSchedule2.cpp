// LC: 210 m 

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        

        // Kahn's Algo
        int n = prerequisites.size();
        vector<int> ans;   // topo sort

        vector<vector<int>> aadjList(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto& course : prerequisites){

          if(course[0] == course[1]) return ans;

          int u = course[1];
          int v = course[0];
          // preReq in -> this courses
          aadjList[u].push_back(v);
          inDegree[v]++;
        }

        queue<int> q;

        // Push all courses with no prerequisites
        for(int i = 0; i < numCourses; i++){
          if (inDegree[i] == 0){
            q.push(i);
            // ans.push_back(i);
          }
        }

        while (!q.empty()){

          int zero_pre = q.front();
          q.pop();
          ans.push_back(zero_pre);

          for(int course : aadjList[zero_pre]){
            inDegree[course]--;
            if(inDegree[course] == 0){
              q.push(course);
              // ans.push_back(course);
            }
          }
        }

        //cycle detected, not DAG
        if (ans.size() != numCourses) return {};
        return ans;
    }
};