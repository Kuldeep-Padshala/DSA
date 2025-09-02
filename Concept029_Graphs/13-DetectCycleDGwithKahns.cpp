class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        

        // Kahn's Algo.
        int n = prerequisites.size();

        vector<vector<int>> aadjList(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto& course : prerequisites){
          
          if(course[0] == course[1]) return false;
          // here
          int u = course[1];
          int v = course[0];

          // preReq in -> this courses
          aadjList[u].push_back(v);
          inDegree[v]++;
        }

        queue<int> q;

        // Push all courses with no prerequisites
        for(int i = 0; i < numCourses; i++){
          if(inDegree[i] == 0){
            q.push(i);
          }
        }

        // topo size
        int count = 0; // count how many courses can be taken

        while (!q.empty()){

            int zero_pre = q.front();
            q.pop();
            count++;

            for(int course : aadjList[zero_pre]){

              inDegree[course]--;
              if(inDegree[course] == 0){
                q.push(course);
              }
            }
        }
        // size of topo sort == vertices
        return count==numCourses;
    }
};