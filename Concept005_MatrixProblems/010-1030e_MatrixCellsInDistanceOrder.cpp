// LC: 1030 e 

class Solution {

    int dist(int r1, int c1, int r2, int c2){
       return abs(r1-r2) + abs(c1-c2);
    }
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        
        vector<pair<int,pair<int,int>>> temp;
        
        for(int i=0; i<rows; i++){
          for(int j=0; j<cols; j++){
              int d = dist(i, j, rCenter, cCenter);
              temp.push_back({d,{i,j}});
          }
        }

        sort(temp.begin(),temp.end());

        vector<vector<int>> ans;

        for(int i=0; i<temp.size(); i++){
            
          int x = temp[i].second.first;
          int y = temp[i].second.second;
          ans.push_back({x,y});
        }
        
        return ans;
    }
};