// inOrder Traversal -> LNR
// L -> go to left
// N -> print node
// R -> go to right

#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

 node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {       // considering it as no child
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void levelOrderTraversal(node* root) {

    if(root == NULL){
        cout << "Tree is empty."<<endl;
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    // 50 20 15 -1 -1 5 -1 -1 30 12 6 -1 -1 6 -1 -1 18 8 -1 -1 10 5 -1 -1 -1

    // 50, null, 

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();                        //removes front

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left != NULL) {
                q.push(temp ->left);
            }

            if(temp ->right != NULL) {
                q.push(temp ->right);
            }
        }
    }

}

void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

int main() {

    node* root = NULL;

    // buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    //creating a Tree
    root = buildTree(root);


    //level order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);

    cout << "inorder traversal is:  ";
    inorder(root); 

    return 0;
}