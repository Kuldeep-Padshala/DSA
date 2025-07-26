// 572. Subtree of Another Tree

// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure 
// and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. 
// The tree tree could also be considered as a subtree of itself.

class Solution {

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      return pre(root, subRoot);
    }


private:

bool pre(TreeNode *s, TreeNode *t) {
  
  return s && (check(s, t) || pre(s->left, t) || pre(s->right, t));
  
  }

bool check(TreeNode *r1, TreeNode *r2) {

  if(r1==NULL && r2==NULL) {
    return true;
  }
  if(r1==NULL || r2==NULL || r1->val != r2->val) {
    return false;
  }
  return check(r1->left, r2->left) && check(r1->right, r2->right);

}

};