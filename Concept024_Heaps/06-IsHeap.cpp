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
    bool isCompleteTree(TreeNode* root) {
        
      return check(root, 0, countNodes(root));
    }
private:

    bool check(TreeNode* root, int i, int count){

      if(root==NULL){
        return true;
      }
      if(i>=count){
        return false;
      }

      return check(root->left, 2*i + 1, count) && check(root->right, 2*i + 2, count);
    }

    int countNodes(TreeNode* root){

      if (root==NULL) {
        return 0;
      }

      return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isHeap(TreeNode* root) {          // max heap

      if (root==NULL) 
      return true;

      // Leaf node
      if (!root->left && !root->right) 
      return true;

      // Only left child
      if (root->left && !root->right)
        return root->val >= root->left->val && isHeap(root->left);

      // Both children
      if (root->left && root->right){

        if(root->val >= root->left->val && root->val >= root->right->val){
          return isHeap(root->left) && isHeap(root->right);
        }
      }

      return false;
    }

};