// LC: 694 m 

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int,int>> &vec, int row0, int col0){

        visited[row][col] = 1;
        vec.push_back({row - row0, col - col0});

        int m = grid.size();
        int n = grid[0].size();

        int del_row[] = {-1, 0, +1, 0};
        int del_col[] = {0, -1, 0, +1};

        for(int i = 0; i < 4; i++){

            int nrow = row + del_row[i];
            int ncol = col + del_col[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, visited, grid, vec, row0, col0);
            }
        }
    }

public:

    int countDistinctIslands(vector<vector<int>>& grid){

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        set<vector<pair<int,int>>> distincts;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(!visited[i][j] && grid[i][j] == 1){   // if found on, find that whole island, store  that pattern of island
                    vector<pair<int,int>> pattern;
                    dfs(i, j, visited, grid, pattern, i, j);
                    distincts.insert(pattern);
                }
            }
        }
        return distincts.size();
    }
};
