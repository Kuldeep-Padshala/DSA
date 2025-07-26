// 965. Univalued Binary Tree

// A binary tree is uni-valued if every node in the tree has the same value.

// Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {

      // if(root->left == NULL && root->right == NULL){
      //   return true;
      // }
      // if(root->left == NULL && (root->right->val == root->val && isUnivalTree(root->right))){
      //   return true;
      // }
      // if(root->right == NULL && (root->left->val == root->val && isUnivalTree(root->left))){
      //   return true;
      // }
      // if( (root->left->val == root->val & isUnivalTree(root->left)) && 
      //     (root->right->val == root->val && isUnivalTree(root->right)) ){
      //       return true;
      //     }
      // return false;

      return (!root->left || (root->left->val == root->val & isUnivalTree(root->left))) &&
               (!root->right || (root->right->val == root->val & isUnivalTree(root->right)));
    
    }
};