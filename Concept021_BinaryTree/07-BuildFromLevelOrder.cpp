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

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
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

int main() {

    node* root = NULL;

    //creating a Tree
    buildFromLevelOrder(root);

    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);

    return 0;
}