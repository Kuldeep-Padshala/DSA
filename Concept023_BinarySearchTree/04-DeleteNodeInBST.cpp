class Solution {
public:

TreeNode* minVal(TreeNode* root){
  TreeNode* temp = root;
  
  while(temp->left != NULL){
    temp = temp->left;
  }
  return temp;
}


    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
          return root;
        }
        if(root->val == key){

          if(root->left == NULL && root->right == NULL){        //zero child
            return NULL;
          }
          if(root->left != NULL && root->right == NULL){        //left child
            TreeNode* temp = root->left;
            delete root;
            return temp;
          }
          if(root->left == NULL && root->right != NULL){        //right child
            TreeNode* temp = root->right;
            delete root;
            return temp;
          }
          if(root->left != NULL && root->right != NULL){        //right child
            int mini = minVal(root->right) -> val;
            root->val = mini;
            root->right = deleteNode(root->right, mini);
            return root;

            // or
            // int maxi = maxVal(root->left) -> val;
            // root->val = maxi;
            // root->left = deleteNode(root->left, maxi);
            // return root;
          }

        }
        else if(key < root->val){
          root->left = deleteNode(root->left, key);
        }
        else{
          root->right = deleteNode(root->right, key);
        }
        return root;
    }
};