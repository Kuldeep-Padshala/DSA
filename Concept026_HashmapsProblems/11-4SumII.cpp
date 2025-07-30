// LC: 454 m

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
      
        unordered_map<int, int> abSum;

        for(int &a: nums1){
          for(int &b: nums2){
            abSum[a+b]++;
          }
        }

        int count = 0;
        for(int &c: nums3){
          for(int &d: nums4){
                       // a+b = -(c+d)
            if(  abSum.count(-(c+d))  )
            count += abSum[-(c+d)];
          }
        }
        return count;
    }
};