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


// parent ni mapping karse, target node return karse
TreeNode* createParentMapping(TreeNode* root, int target, map<TreeNode*,TreeNode*> &nodeToParent){

  TreeNode* res = NULL;
  queue<TreeNode*> q;
  q.push(root);
  nodeToParent[root] = NULL;

  while(!q.empty()){                     //level order traversal
    TreeNode* front = q.front();
    q.pop();

    
    if(front->val == target){
      res = front;
    }
    if(front->left != NULL){
      nodeToParent[front->left] = front;
      q.push(front->left);
    }
    if(front->right != NULL){
      nodeToParent[front->right] = front;
      q.push(front->right);
    }
  }
  return res;
}

int infectTree(TreeNode* root, map<TreeNode*,TreeNode*> &nodeToParent){
  
  map<TreeNode*,bool> visited;
  queue<TreeNode*> q;

  q.push(root);
  visited[root] = true;

  int time = 0;

  while(!q.empty()){

    bool flag = 0;     // queue ma kai add thyu ke nai
    int n = q.size();

    for(int i=0;i<n;i++){    // badha adjacent nodes ne visit karva

      TreeNode* front = q.front();
      q.pop();

      

      if(front->left != NULL  && !visited[front->left]){    // left ne infect kairo jo pelethi infected no hoi to
        flag = 1;
        q.push(front->left);
        visited[front->left] = 1;
      }
      if(front->right != NULL  && !visited[front->right]){    // right ne infect kairo
        flag = 1;
        q.push(front->right);
        visited[front->right] = 1;
      }
      if(nodeToParent[front] != NULL && !visited[nodeToParent[front]]){    //parent ne infect kare chhe
        flag = 1;
        q.push(nodeToParent[front]);
        visited[nodeToParent[front]] = 1;
      }

    }
    if(flag == 1){
      time++;
    }
  }
  return time;
}


TC: O(n)
// step1: map banaivo parent ne access karva
// step2: createmap ni sathe target return karavyo
// step3: target node thi infect karvanu chalu karyu

    int amountOfTime(TreeNode* root, int start) {
      
      int time = 0;
      map<TreeNode*,TreeNode*> nodeToParent;
      TreeNode* targetNode = createParentMapping(root, start, nodeToParent);

      time = infectTree(targetNode, nodeToParent);

      return time;
    }
};