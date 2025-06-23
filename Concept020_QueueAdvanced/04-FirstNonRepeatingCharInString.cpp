class Solution {
  public:
    string FirstNonRepeating(string &s) {
        
         map<char, int> m;
		    string ans = "";
		    queue<char> q;
		    
		    for(int i=0; i<s.length(); i++) {
		        char ch = s[i];
		        
		        q.push(ch);
		        m[ch]++;
		        
		        while(!q.empty()) {
		            if(m[q.front()] > 1){
		                q.pop();
		            }
		            else
		            {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
    }
};