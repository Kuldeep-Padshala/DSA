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

void convertToSortedDLL(TreeNode *root, TreeNode* &head){

  if(root==NULL){
    return NULL;
  }

  convertToSortedDLL(root->right, head);   // why right first and then left
  root->right = head;

  if(head!=NULL){
    head->left = root;
  }
  head = root;
  convertToSortedDLL(root->left, head);
}

TreeNode *mergeTwoLists(TreeNode *head1, TreeNode *head2) {
        
  TreeNode* head = NULL;
  TreeNode* tail = NULL;

  while (head1 && head2) {
    
  if(head1->val <= head2->val) {

    if(head==NULL){
      head = head1;
    }
    else{
      tail->right = head1;
      head1->left = tail;
    }

    tail = head1;
    head1 = head1->right;

  } 
  else{
    
    if(head==NULL){
      head = head2;
    }
    else{
      tail->right = head2;
      head2->left = tail;
    }

    tail = head2;
    head2 = head2->right;
    
  }

  }
  while(head1!=NULL){
    tail->right = head1;
    head1->left = tail;
    tail = head1;
    head1 = head1->right;
  }

  while(head2!=NULL){
    tail->right = head2;
    head2->left = tail;
    tail = head2;
    head2 = head2->right;
  }
  return head;
}


  
    
};