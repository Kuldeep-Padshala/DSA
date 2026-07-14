// LC: 303 e 

class NumArray {
public:

    vector<int> nums;
    vector<int> prefixSum;

    NumArray(vector<int>& nums) {
        
        this->nums = nums;

        prefixSum.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
          prefixSum.push_back(prefixSum[i-1] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        
        return prefixSum[right] - (left == 0 ? 0 : prefixSum[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */