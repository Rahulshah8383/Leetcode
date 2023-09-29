class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum == x){
            return nums.size();
        }
        int sum_to_make = totalSum - x;

        int ans = 0;
        int sum = 0;
        int start = 0, end = 0;

        while(end<nums.size()){
            sum = sum + nums[end];
            
            while(start<end && sum > sum_to_make){
                sum -= nums[start++];
            }

            if(sum == sum_to_make){
                ans = max(ans, end-start+1);
            }

            end++;
        }

        return ans==0 ? -1 : nums.size()-ans;
    }
};
