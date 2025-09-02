// LC: 951 m

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

  bool solve(TreeNode* root1, TreeNode* root2){

    // if(root1 == NULL && root2 == NULL){
    //   return true;
    // }
    // both side NULL
    if(root1->left == NULL && root1->right == NULL && root2->left == NULL && root2->right == NULL){
      return true;
    }

    // left side NULL
    if((root1->left == NULL && root1->right != NULL) && (root2->left == NULL && root2->right != NULL)){
      if(root1->right->val == root2->right->val){
        return solve(root1->right, root2->right);
      }
      else{
        return false;
      }
    }

    // right side NULL
    if((root1->left != NULL && root1->right == NULL) && (root2->left != NULL && root2->right == NULL)){
      if(root1->left->val == root2->left->val){
        return solve(root1->left, root2->left);
      }
      else{
        return false;
      }
    }

    // oposite side NULL
    if((root1->left == NULL && root1->right != NULL) && (root2->left != NULL && root2->right == NULL)){
      if(root1->right->val == root2->left->val){
        return solve(root1->right, root2->left);
      }
      else{
        return false;
      }
    }

    // oposite side NULL
    if((root1->left != NULL && root1->right == NULL) && (root2->left == NULL && root2->right != NULL)){
      if(root1->left->val == root2->right->val){
        return solve(root1->left, root2->right);
      }
      else{
        return false;
      }
    }

    if(((root1->left && root1->right) && (!root2->left || !root2->right)) 
    || ((!root1->left || !root1->right) && (root2->left && root2->right))
    || ((!root1->left && !root1->right) && (root2->left || root2->right))
    || ((root1->left || root1->right) && (!root2->left && !root2->right))){
      return false;
    }

    // noth side exists
    if((root1->left->val == root2->left->val) && (root1->right->val == root2->right->val)){
      return (solve(root1->left, root2->left) && solve(root1->right, root2->right));
    }

    if((root1->left->val == root2->right->val) && (root1->right->val == root2->left->val)){
      return (solve(root1->left, root2->right) && solve(root1->right, root2->left));
    }

    else{
      return false;
    }
  }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        if(root1==NULL && root2==NULL) return true;
        if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)) return false;
        if(root1->val != root2->val) return false;
        return solve(root1, root2);
    }
};

// class Solution {
//     bool solve(TreeNode* root1, TreeNode* root2) {
//         if (!root1 && !root2) return true;       // both null
//         if (!root1 || !root2) return false;      // one null
//         if (root1->val != root2->val) return false; // mismatch
        
//         // two cases: no flip OR flip
//         bool noFlip = solve(root1->left, root2->left) && solve(root1->right, root2->right);
//         bool flip   = solve(root1->left, root2->right) && solve(root1->right, root2->left);

//         return noFlip || flip;
//     }
// public:
//     bool flipEquiv(TreeNode* root1, TreeNode* root2) {
//         return solve(root1, root2);
//     }
// };