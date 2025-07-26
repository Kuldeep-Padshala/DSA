class node{
    public:
      int data;
      int i;
      int j;
};

class compare{
    public:
      bool operator(node*a, node* b){
          return a->data > b->data;
      }
}

class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        priority_queue<node*, vector<node*>, compare> minHeap;

        //step 1: push first element of each array into the min heap
        for(int i=0; i<K; i++){
            node* temp = new node();
            temp->data = ;
            temp->i = i;
            temp->j = 0;
            minHeap.push(temp);
        }

        vector<int> ans;

        //step 2: pop the top element from the min heap and push the next element from the same array
        while(!minHeap.empty()){

            node* temp = minHeap.top();
            minHeap.pop();

            ans.push_back(temp->data);

            int i = temp->i;
            int j = temp->j;

            if(j+1 < arr[i].size()){            // if next element of ith row i.e j+1 is present
                node* next = new node();
                next->data = arr[i][j+1];
                next->i = i;
                next->j = j+1;
                minHeap.push(next);
            }
        }
        return ans;
    }
};