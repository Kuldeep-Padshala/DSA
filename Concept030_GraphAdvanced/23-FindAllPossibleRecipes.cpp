// LC: 2115 m 

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_set<string> supply(supplies.begin(), supplies.end());

        //            ingred    used in recipes
        unordered_map<string, vector<string>> useToMake; // ingredient → recipes needing it
        //         recipies  ingre req.
        unordered_map<string, int> needed;         // how many ingredients each recipe still needs

       
        // Build useToMake and needed
        for(int i=0; i<recipes.size(); i++){

          //  this recipe   needs this much ingredients
          needed[recipes[i]] = ingredients[i].size();

          for(auto& ingre: ingredients[i]){
            useToMake[ingre].push_back(recipes[i]);
          }

        }

        queue<string> q;
        // Start with all supplies: they are immediately available
        for(auto& sup : supplies){
          q.push(sup);
        }

        vector<string> ans;

        while(!q.empty()){

          string item = q.front();
          q.pop();

          for(string& recipe: useToMake[item]){
            needed[recipe]--;
            if(needed[recipe] == 0){
              ans.push_back(recipe);
              q.push(recipe);   // cause recipe can also be used as an ingredient
            }
          }
        }
        return ans;

    }
};