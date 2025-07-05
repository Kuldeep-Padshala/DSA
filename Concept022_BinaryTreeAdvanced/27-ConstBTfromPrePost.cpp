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

int findPos(vector<int>& postorder, int elem, int postStart, int postEnd) {

    for(int i = postStart; i <= postEnd; i++) {
        if(postorder[i] == elem)
            return i;
    }
    return -1;
}

TreeNode* solve(vector<int>& preorder, vector<int>& postorder,int &index,int postStart,int postEnd, int n){

  if(index >= n || postStart > postEnd)
  return NULL;

  int element = preorder[index++];
  TreeNode* root = new TreeNode(element);

  if (index >= n || postStart == postEnd)
  return root;

  int nextElement = preorder[index];    // this step added
  int pos = findPos(postorder,nextElement, postStart, postEnd);

  root->left = solve(preorder, postorder, index, postStart, pos, n);
  root->right = solve(preorder, postorder, index, pos+1, postEnd-1, n);

  return root;
}

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIndex = 0;
        int n = preorder.size();
        TreeNode* ans = solve(preorder, postorder, preIndex, 0, n-1, n);
        return ans;
    }
};