/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
  
  pair<bool, int> isSumTreeFast(Node* root){

  if(root == NULL){
    pair<bool,int> p = make_pair(true, 0);
    //pelo int -> bool, bijo int->height
    return p;
    // return {true, 0};   can also be written
  }

//   we can also do this
//   if(root->left == NULL && root->right==NULL){
//     pair<bool,int> p = make_pair(true, root->data);
//     return p; 
//   }

  pair<bool,int> left = isSumTreeFast(root->left);
  pair<bool,int> right = isSumTreeFast(root->right);

  pair<bool, int> ans;

  ans.first = ((root->data == (left.second + right.second)) || (root->left == NULL  && root->right==NULL)) && left.first && right.first;
  ans.second = (left.second + right.second)+root->data;

  return ans;

}
    bool isSumTree(Node* root) {
        // Your code here
        return isSumTreeFast(root).first;
    }
};