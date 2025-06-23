// TC: O(n)

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        deque<long long int> dq;
         vector<int> ans;
         int negative = -1;
         
         //process first window
         for(int i=0; i<k; i++) {
             if(arr[i] < 0) {
                 dq.push_back(i);
             }
         }
         
         //push ans for FIRST window
         if(dq.size() > 0) {
             ans.push_back(arr[dq.front()]);
         }
         else
         {
             ans.push_back(0);
         }
         
         //now process for remaining windows
         for(int i = k; i < arr.size(); i++) {
             //first pop out of window element
             
             
             if(!dq.empty() && (i - dq.front())>=k ) {     // here (i-dq.front())>=k means that the element at dq.front() is out of the current window. 
                                                          // explaination in detail: so if i = 5 and k = 3, then the current window is [3,4,5] and the element at dq.front() is at index 2. So (5-2) >= 3 is true, which means that the element at dq.front() is out of the current window.
                 dq.pop_front();
             }
             
             //then push current element
             if(arr[i] < 0)
                dq.push_back(i);
             
            // put in ans
            if(dq.size() > 0) {
                 ans.push_back(arr[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
         }
         return ans;
    }
};