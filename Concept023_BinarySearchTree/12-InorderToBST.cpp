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