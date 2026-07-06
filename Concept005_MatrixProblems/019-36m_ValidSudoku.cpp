// LC: 36 m 

class Solution {

    Return true if subarray board[start_row : end_row - 1][start_col : end_col - 1]
    contains any duplicates in [1 : num_elements]; otherwise return false.

    bool anyDuplicate(auto& board, int start_row, int end_row, int start_col, int end_col, int num_elements) {
        
        vector<bool> is_present(num_elements + 1, false);

        for(int i = start_row; i<end_row; i++){
          for(int j = start_col; j<end_col; j++){
            
              if(board[i][j] != '.'){
                if(is_present[board[i][j] - '0']){
                  return true;
                }
                is_present[board[i][j] - '0'] = true;
              }
          }
        }
        return false;
    }

public:
    bool isValidSudoku(const vector<vector<char>>& board) {

        // vector<vector<bool>> rows(9, vector<bool>(9, false));
        // vector<vector<bool>> cols(9, vector<bool>(9, false));
        // vector<vector<bool>> boxes(9, vector<bool>(9, false));

        // for(int i=0; i<9; i++){
        //   for(int j=0; j<9; j++){
            
        //     char ch = board[i][j];
        //     if (ch == '.') continue;           // empty cell
        //     int data = ch - '1';                 // map '1'..'9' -> 0..8
        //     int boxIndex = (i / 3) * 3 + (j / 3);

        //     // If already seen in row/col/box -> invalid
        //     if(rows[i][data] || cols[j][data] || boxes[boxIndex][data]) return false;

        //     // mark seen
        //     rows[i][data] = cols[j][data] = boxes[boxIndex][data] = true;
        //   }
        // }
        // return true;

        
        int n = board.size();

        // Check row constraints.
        for(int i=0; i<n; i++){
          if(anyDuplicate(board, i, i+1, 0, n, n)){
            return false;
          }
        }

        // Check column constraints.
        for(int j=0; j<n; j++){
          if(anyDuplicate(board, 0, n, j, j+1, n)) {
            return false;
          }
        }

        // Check region constraints.
        int size = sqrt(n);    // region size

        for(int i=0; i<n; i+=size){
          for(int j=0; j<n; j+=size){

            if(anyDuplicate(board, i, i+size, j, j+size, n)){
              return false;
            }
          }
        }
        return true;
    }
};