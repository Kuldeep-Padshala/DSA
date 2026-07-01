// LC: 2201 m 

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        
        int id = 1;      // dar artifact nu id

        map<pair<int,int>,int>mp;
        unordered_map<int,int>cnt;     // counts total cells of each artifact

        for(auto& a: artifacts){

          int r1=a[0], c1=a[1];
          int r2=a[2], c2=a[3];

          for(int row=r1; row<=r2; row++){
            for(int col=c1; col<=c2; col++){

              mp[{row,col}] = id;
              cnt[id]++;
            }
          }
          id++;
        }

        int count = cnt.size();

        for(auto& d: dig){

          int row = d[0];
          int col = d[1];

          if(mp.find({row, col}) == mp.end()) continue;

          int Id = mp[{row, col}];
          cnt[Id]--;

          if(cnt[Id]==0) cnt.erase(Id);
        }

        int count2 = cnt.size();
        return count-count2;
    }
};