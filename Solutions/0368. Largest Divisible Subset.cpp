class Solution {
public:
    // void Helper(vector<vector<int>>& ans, vector<int>& nums, vector<int> output, int idx) {
    //     if (idx >= nums.size()) {
    //         ans.push_back(output);
    //         return;
    //     }

    //     Helper(ans, nums, output, idx + 1);

    //     int element = nums[idx];
    //     if (output.empty()) {
    //         output.push_back(element);
    //     } else {
    //         int top = output.back();
    //         if (element % top == 0 || top % element == 0) {
    //             output.push_back(element);
    //         }
    //     }

    //     Helper(ans, nums, output, idx + 1);
    // }

    // vector<int> largestDivisibleSubset(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     vector<int> output;
    //     sort(nums.begin(), nums.end());
    //     Helper(ans, nums, output, 0);

    //    vector<int> result;
    //     for (auto& x : ans) {
    //         if (x.size() > result.size()) {
    //             result = x;
    //         }
    //     }
    //     return result;
    // }


    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(), maxi=1, num=-1;
        vector<int>v;
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(!(nums[i]%nums[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    if(maxi<dp[i]){
                        maxi=dp[i];
                    }
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            if(maxi==dp[i] && (num==-1 || !(num%nums[i]))){
                v.push_back(nums[i]);
                maxi--;
                num=nums[i];
            }
        }
        return v;
    }
};
