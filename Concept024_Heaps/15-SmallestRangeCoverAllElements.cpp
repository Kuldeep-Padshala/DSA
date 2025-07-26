class Node {
  public:

  int data;
  int row;
  int col;
  int n;    // size of each list

  Node(int data, int row, int col, int n){

    this->data = data;
    this->row = row;
    this->col = col;
    this->n = n;
  }
};

class compare {
    public:
    bool operator() (Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        //approach 1 
        // TC:O(n*k*k) SC:O(k)
        // store head of all lists and find min and max
        // now in that range try changing min value for smallest range

        // approach 2 using minHeap
        // TC: O(k*n logk)  SC:O(k)


        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<Node*, vector<Node*>, compare> minHeap;

        // first element of each list in minHeap
        for(int i=0; i<nums.size(); i++){         // O(log k)

          int element = nums[i][0];
          mini = min(mini, element);
          maxi = max(maxi, element);
          minHeap.push(new Node( element, i, 0, nums[i].size() ));
        }


        int start = mini, end = maxi;

        // koi ek list puro no thai tya sudhi
        while(!minHeap.empty()){                 // O(k*n)

          Node* temp = minHeap.top();
          minHeap.pop();    // returns void
          mini = temp -> data;

          // update start end if range gets better
          if( (maxi-mini) < (end-start) ){
            start = mini;
            end = maxi;
          }

          // jo list ma elements hoi to move to next element in the same list
          if(temp->col + 1< temp->n){
            maxi = max(maxi, nums[temp->row][temp->col + 1]);

            // pushing that element in minHeap
            minHeap.push(new Node( nums[temp->row][temp->col + 1], temp->row, temp->col+1, temp->n));
          }
          else{ // list is empty
            break;
          }
        }
        return {start, end};
    }
};