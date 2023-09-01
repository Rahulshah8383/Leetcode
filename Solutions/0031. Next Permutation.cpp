class Solution {
public:
   void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        
        // Step 1: Find the break point:
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                // index i is the break point
                idx = i;
                break;
            }
        }

        // If break point does not exist:
        if(idx == -1){
            return reverse(nums.begin(), nums.end());
        }

        // Step 2: Find the next greater element and swap it with arr[ind]:
        for(int i=n-1;i>idx;i--){
            if(nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // Step 3: reverse the right half:
        return reverse(nums.begin()+idx+1, nums.end());
    }
};
