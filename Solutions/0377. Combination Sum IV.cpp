class Solution {
public:
    // int recursion(vector<int>& nums, int target){
    //     if(target < 0){
    //         return 0;
    //     }
    //     if(target == 0){
    //         return  1;
    //     }

    //     int ans = 0;
    //     for(int i=0;i<nums.size();i++){
    //         ans += recursion(nums, target-nums[i]);
    //     }

    //     return ans;
    // }

    // int memorization(vector<int>& nums, int target, vector<int>& dp){
    //     if(target < 0){
    //         return 0;
    //     }
    //     if(target == 0){
    //         return  1;
    //     }

    //     if(dp[target] != -1){
    //         return dp[target];
    //     }

    //     int ans = 0;
    //     for(int i=0;i<nums.size();i++){
    //         ans += memorization(nums, target-nums[i], dp);
    //     }

    //     dp[target] = ans;

    //     return dp[target];
    // }

    int tabular(vector<int>& nums, int target){
        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if((i-nums[j]) >= 0)
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        // return recursion(nums, target);

        // vector<int> dp(target+1, -1);
        // return memorization(nums, target, dp);

        return tabular(nums, target);
    }
};
