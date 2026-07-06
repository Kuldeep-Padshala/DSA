// LC: 56 m 

class Solution {
public:
    int nextGreaterElement(int n) {
        
        // Two pointer

        // string ma convert
        string nums = to_string(n);    // 124651

        
        int size = nums.length();
        int i = size-1;
        while(i>0 && nums[i-1] >= nums[i]){        // 124'6'51   6 --> i, 4 --> i-1
          i--;
        }

        if (i == 0) {           // digit no maido, aa sauthi moto number chhe
          return -1;
        }


        int j = size-1;
        while (j > i-1 && nums[j] <= nums[i-1]) {     // 1246'5'1, smallest digit on right to i-1 greater than nums[i-1]
          j--;
        }

        swap(nums[i-1], nums[j]);           // 124651  --> 125641

        reverse(nums.begin() + i, nums.end());    //  125 641  --> 125 146

        long ans = stol(nums);

        return (ans <= INT_MAX) ? (int)ans : -1;
    }
};