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

bool longestPathSum(TreeNode* node,int sum, int target) {
      
        // code here
        
        if (node == NULL){
          return false; 
        }
        sum += node->val;
        if(node->left == NULL && node->right == NULL){

          if(sum == target) return true;
          else return false;
        }   

        // Explore left and right
        bool left = longestPathSum(node->left, sum, target);
        bool right = longestPathSum(node->right, sum, target);

        // Choose path with greater height or greater sum if heights are equal
        if(left || right) return true;
        else return false;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return longestPathSum(root,0,targetSum);
    }
};