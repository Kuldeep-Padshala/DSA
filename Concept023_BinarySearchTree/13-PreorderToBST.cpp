class Solution {
public:

TreeNode* solve(vector<int>& preorder, int min, int max, int &i){    // i has to be passed by address

  if(i>=preorder.size()){
    return NULL;
  }
  if(preorder[i]<min || preorder[i]>max){
    return NULL;
  }
  TreeNode* root = new TreeNode (preorder[i++]);
  root->left = solve(preorder, min, root->val, i);
  root->right = solve(preorder, root->val, max, i);

  return root;
}

    TreeNode* bstFromPreorder(vector<int>& preorder) {

      // Approach1 TC:O(n*n)
      // normally insertIntoBSt

      // Approach2 TC:O(n logn)
      // sort pre order to get inorder
      // make bst from inorder-preorder

      // Aproach3 TC:O(3n)~O(n)
      // just like search in bst, keeping range
      
      int i = 0;
      return solve(preorder, INT_MIN, INT_MAX, i);
    }
};