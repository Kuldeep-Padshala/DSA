// we need SC:O(1), we use morris traversal

// curr = root;
// while(curr!=NULL){

//     if(curr->left exist){
//         prev = curr->left;

//         while(prev->right exist){
//             prev = prev->right;
//         }
//         prev->right = curr->right;
//         curr->right = curr->left;
//     }
//     curr = curr->right
// }

// Representation of input binary tree:
    //           1
    //          / \
    //         2   3
    //        / \  
    //       4   5


class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode* curr = root;
        while(curr!=NULL){

          if(curr->left){

            TreeNode* pred = curr->left;    // ek left ma ane pachi right null no thai tya sudhi
            while(pred->right)
              pred = pred->right;

            pred->right = curr->right;     // left part no end -> right starting
            curr->right = curr->left;        //    TreeNode -> left, NLR
            curr->left = NULL;             // have left part no use nathi
          }
          curr = curr->right;
        }
    }
};