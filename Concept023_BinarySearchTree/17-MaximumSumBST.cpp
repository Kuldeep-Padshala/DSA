class Solution {
public:

class Info{
  public:

  int mini;
  int maxi;
  bool isBST;
  int sum;
};

Info solve(TreeNode* root, int&ans){

  if(root==NULL){
    return {INT_MAX, INT_MIN, true, 0};
  }

  Info left = solve(root->left, ans);
  Info right = solve(root->right, ans);

  Info curr;

  curr.mini = min(root->val, left.mini);
  curr.maxi = max(root->val, right.maxi);
  curr.isBST = left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini);
  curr.sum = left.sum + right.sum + root->val;

  if(curr.isBST){
    ans = max(ans, curr.sum);
  }
  return curr;
}

    int maxSumBST(TreeNode* root) {

      int ans = 0;
      Info temp = solve(root, ans);
      return ans;
    }
};