// LC: 2350 h 

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        
        unordered_set<int> st;
        int ans  = 1;
        for(int i: rolls){
          
          st.insert(i);
          if(st.size() == k){
            ans ++;
            st.clear();
          }
        }
        return ans;

    }
};