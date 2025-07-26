class Solution {
  public:
    
    
    // int signum(int a, int b){
        
    //     if(a==b) return 0;
    //     if(a>b) return 1;
    //     else return -1;
    // }
    
    void findMedian(int element, priority_queue<int>& maxHeap, 
    priority_queue<int, vector<int>, greater<int>>& minHeap, double &median){
        
        int maxi = maxHeap.size();
        int mini = minHeap.size();
        
        // case 1: left and right are equal
        if(maxi == mini){
            if(element > median){        // median karta moto  elem, right ma push
                minHeap.push(element);
                median = minHeap.top();
            }
            else{
                maxHeap.push(element);   // baki left ma
                median = maxHeap.top();
            }
        }
        
        // case 1: left greater than right
        else if(maxi > mini){
            if(element > median){       // right ma push
                minHeap.push(element);
                median = (minHeap.top()+maxHeap.top())/2.0;
            }
            else{
                minHeap.push(maxHeap.top());    // equal karva
                maxHeap.pop();
                maxHeap.push(element);
                median = (minHeap.top()+maxHeap.top())/2.0;
            }
        }
        
        // case 2: right greater than left
        else{
            if(element>median){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);
                median = (minHeap.top()+maxHeap.top())/2.0;
            }
            else{
                maxHeap.push(element);
                median = (minHeap.top()+maxHeap.top())/2.0;
            }
        }
    }
    
    vector<double> getMedian(vector<int> &arr) {
        
        // approach 1
        // insertion sort
        // TC:O(n*n)
        
        
        
        // approach 2
        // Left part is maxHeap: top(max) contains left elem of median
        // RightPart is minHeao: top(min) contains right elem of median
        
        vector<double> ans;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        double median = 0.0;
        
        for(int i=0; i<arr.size(); i++){
            findMedian(arr[i], maxHeap, minHeap, median);
            ans.push_back(median);
        }
        return ans;
    }
};
