// LC: 2171 m 

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        long long n = beans.size();
        long long ans = LLONG_MAX;
        long long sum = accumulate(begin(beans), end(beans), 0LL);

        sort(begin(beans), end(beans));

        for (int i=0; i<n; i++){
          ans = min(ans, sum - (n-i) * beans[i]);
        }
        return ans;
    }
};