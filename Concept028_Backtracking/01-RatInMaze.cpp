// Rat in a maze

class Solution {
  public:
  
  bool isSafe(int x, int y, vector<vector<int>>& maze, int n){
      
      if( (x>=0 && x<n) && (y>=0 && y<n) && maze[x][y] == 1){
          return true;
      }
      else{
          return false;
      }
  }
  
  void solve(int x, int y, int n, vector<vector<int>>& maze, vector<string>& ans, string str){
      
      // base case
      if(x==n-1 && y==n-1){
          ans.push_back(str);
          return;
      }
      
      // D L R U
      maze[x][y] *= -1;                 // jai e pela ane visited mark karse
      
      // Down
      if(isSafe(x+1, y, maze, n)){
          
          solve(x+1, y, n, maze, ans, str+'D');
          
      }
      
      // Left
      if(isSafe(x, y-1, maze, n)){
          
          solve(x, y-1, n, maze, ans, str+'L');
          
      }
      
      // Right
      if(isSafe(x, y+1, maze, n)){
          
          solve(x, y+1, n, maze, ans, str+'R');
          
      }
      
      // Up
      if(isSafe(x-1, y, maze, n)){
          
          solve(x-1, y, n, maze, ans, str+'U');

      }
      
      maze[x][y] *= -1;      // pacho ave tyare non visited mark karse, karan ke bijo path ayathi jai shake
      
      
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        // lexicographical -> D L R U
        
        vector<string> ans;
        
        string str = "";
        
        //   x   y     n        matrix  ans   path
        solve(0, 0, maze.size(), maze,  ans, str);
        
        return ans;
    }
};