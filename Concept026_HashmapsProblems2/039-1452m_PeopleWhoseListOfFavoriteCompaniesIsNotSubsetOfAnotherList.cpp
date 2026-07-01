// LC: 1452 m 

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        
        int n = favoriteCompanies.size();
        vector<unordered_set<string>>vec;

        for(auto& list: favoriteCompanies){
          
          unordered_set<string> st;
          for(string& company: list){
            st.insert(company);
          }
          vec.push_back(st);
        }

        vector<int>ans;

        // for(int i=0; i<n; i++){

        //   bool isSubset = false;

        //   for(int j=0; j<n; j++){

        //     if(i == j) continue;

        //     bool allFound = true;  // assume all companies of i exist in j

        //     for(string company : favoriteCompanies[i]){
              
        //       if(vec[j].find(company) == vec[j].end()) {
        //         allFound = false;
        //         break;
        //       }
        //     }

        //     // if all companies of i are found in j, then i is a subset
        //     if(allFound) {
        //       isSubset = true;
        //       break;
        //     }
        //   }

        //   // if i is NOT a subset of any list, add it to answer
        //   if(!isSubset){
        //     ans.push_back(i);
        //   }
        // }

        for(int i=0; i<n; i++){

          bool isSubset = false;

          for(int j=0; j<vec.size(); j++){
              
            if (i==j) continue;
            bool allFound=true;

            for(int k=0;k<favoriteCompanies[i].size();k++){
              if (vec[j].find(favoriteCompanies[i][k])==vec[j].end()){
                allFound=false;
                break;
              }
            }
            if(allFound){
              isSubset=true;
              break;
            }
          }
          if(!isSubset){ans.push_back(i);}
        }
        
        return ans;
    }
};