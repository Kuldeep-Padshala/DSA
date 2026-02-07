class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // sliding window

        int n = s.length();
        int st=0, end=0, ans=0;

        unordered_set<char> mp;

        while(end<n){

          if(mp.find(s[end]) == mp.end()) { // Unique character
            
            mp.insert(s[end]);
            ans = max(ans, end-st+1);
            end++;  // Expand the window
          }

          else{                   // Duplicate found
            mp.erase(s[st]);
            st++;  // Shrink the window
          }
        }
        return ans;

        // int ans = 0;
        // int start = 0;        // s boundry
        // unordered_map<char, int> mp;

        // for(int i=0; i<s.size(); i++){
            
        //   // found char AND it is inside our current window
          
        //   if(mp.count(s[i]) && mp[s[i]] >= start){
        //     start = mp[s[i]] + 1;
        //   }

        //   mp[s[i]] = i;

        //   //        (currIdx - startIdx + 1)
        //   ans = max(ans, i - start + 1);
        // }

        // return ans;
    }
};