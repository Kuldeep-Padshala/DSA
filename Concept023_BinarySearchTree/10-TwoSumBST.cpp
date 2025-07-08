class Solution {
public:


// Given the root of a binary search tree and an integer k, return true 
// if there exist two elements in the BST 
// such that their sum is equal to k, or false otherwise.

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

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, &ans);

        int i=0, j=ans.size()-1;
        while(i<j){
          int sum = ans[i] + ans[j];
          if(sum==k){
            return true;
          }
          else if(sum<k){
            i++;
          }
          else{
            j--;
          }
        }
        return false;
    }
};