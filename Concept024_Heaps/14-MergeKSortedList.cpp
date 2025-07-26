/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

// TC:O(n*k log k)
class compare {
    public:
    bool operator() (Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        
        // Min heap, head Nodes of lists
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        
        int k = arr.size();
        
        for(int i=0; i<k; i++){    // badha lists na head nodes ne min heap ma push karva
            
            if(arr[i] != NULL){
                minHeap.push(arr[i]);
            }
        }
        
        Node* head = NULL;
        Node* tail = NULL;
        
        while(minHeap.size()>0){
            Node* top = minHeap.top();
            minHeap.pop();
            
            
            if(top->next != NULL){
                minHeap.push(top->next);
            }
            if(head == NULL){
                head = top;
                tail = top;
            }
            else{
                tail->next = top;
                tail = top;
                
            }
        }
        return head;
        
    }
};