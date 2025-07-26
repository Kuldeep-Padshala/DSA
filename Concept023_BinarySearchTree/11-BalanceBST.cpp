class Solution {
public:

void inorder(TreeNode* root, vector<int>* s) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, s);
   	
    //leaf node
    s->push_back(root->val);
    
    inorder(root->right, s);
}

TreeNode* inoToBST(int s, int e, vector<int> ino){

  if(s>e){
    return NULL;
  }
  int mid = (s+e)/2;

  TreeNode* root = new TreeNode(ino[mid]);
  root->left = inoToBST(s, mid-1, ino);
  root->right = inoToBST(mid+1, e, ino);
  return root;
}

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, &ans);

        return inoToBST(0, ans.size()-1, ans);
    }
};