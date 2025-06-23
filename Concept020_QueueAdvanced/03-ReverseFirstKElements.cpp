// TC: O(n)

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        stack<int> s;
        
        if(q.size()<k){
            return q;
        }
    
    for(int i = 0; i<k; i++) {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()) {
        q.push(s.top());   //its push back
        s.pop();
    }
    
    int t = q.size()-k;
    
    while(t--) {
        q.push(q.front());
        q.pop();
    }
    
    return q;
    }
};