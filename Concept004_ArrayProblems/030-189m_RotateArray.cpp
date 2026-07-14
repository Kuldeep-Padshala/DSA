class Solution {

    void reverseArraySegment(vector<int>& nums, int s, int e) {
      
      while (s < e) {
          swap(nums[s], nums[e]);
          s++;
          e--;
      }
    }
public:
    void rotate(vector<int>& nums, int k) {
      
        int n = nums.size();

        // If the array is empty or contains only one element, no need to rotate
        if(k==0 || k%n == 0){
          return;
        }
        
        k = k % n;

        // Reverse the entire array
        reverseArraySegment(nums, 0, n-1);

        // Reverse the first k elements
        reverseArraySegment(nums, 0, k-1);

        // Reverse the remaining n - k elements
        reverseArraySegment(nums, k, n-1);

        // Brute Force 
        
        // int n=nums.size();
        // vector<int> arr(n);

        // while(k>n){
        //   k-=n;
        // }

        // for(int i=0;i<n;i++){
        //   arr[i]=nums[i];
        // }

        // for(int j=0; j<n; j++){
        //   if(j+k<n){
        //     nums[j+k]=arr[j];
        //   }
        //   else{
        //     nums[j+k-n]=arr[j];
        //   }
        // }
    }
};