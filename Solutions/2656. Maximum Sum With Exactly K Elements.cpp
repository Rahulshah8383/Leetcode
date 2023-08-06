class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size()-1;
        int sum = 0;
        while(k){
            sum = sum + nums[n];
            nums[n] = nums[n] + 1;
            k--;
        }
        
        return sum;
    }
};
