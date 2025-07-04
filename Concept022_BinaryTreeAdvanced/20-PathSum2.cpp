/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

pair< pair<bool, vector<int> > , vector<vector<int>> > pathSum2(TreeNode* node,int sum, int target ,vector<int>v, vector<vector<int>>ans) {
      
        // code here
        
        if (node == NULL){
          return { {false,v }, ans}; 
        }
        sum += node->val;
        v.push_back(node->val);

        if(node->left == NULL && node->right == NULL){

          if(sum == target){
            ans.push_back(v);
            // v.clear();
            return { {true,v }, ans};
          }  
          
          else return { {false,v }, ans};
        }

        // Explore left and right
        // auto left = pathSum2(node->left, sum, target, v, ans);
        // ans = left.second;
        // auto right = pathSum2(node->right, sum, target, v, ans);

        // Choose path with greater height or greater sum if heights are equal
        // if(left.first.first || right.first.first) return { {true,v }, ans};
        // else return { {false,v }, ans};

        auto left = pathSum2(node->left, sum, target, v, ans);
        auto right = pathSum2(node->right, sum, target, v, ans);

    vector<vector<int>> mergedAns = left.second;
    mergedAns.insert(mergedAns.end(), right.second.begin(), right.second.end());

    // ✅ FIXED: propagate proper flag
    bool found = left.first.first || right.first.first;

    return { {found,v }, mergedAns };
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

      vector<int> v;
      vector<vector<int>> ans;

      return pathSum2(root, 0, targetSum, v, ans).second; 

    }
};