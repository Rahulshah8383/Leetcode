class Solution {
public:
    /*
    int memorization(vector<int>& nums, int n, int idx, int prev_idx, vector<vector<int>> &dp){
        if(idx == n){
            return 0;
        }

        if(dp[idx][prev_idx+1] != -1){
            return dp[idx][prev_idx+1];
        }

        int notTake = 0 + memorization(nums, n, idx+1, prev_idx, dp);
        int take = 0;

        if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
            take = 1 + memorization(nums, n, idx+1, idx, dp);
        }

        dp[idx][prev_idx+1] = max(take, notTake);

        return dp[idx][prev_idx+1];
    }
    */

    /*
    int tabulation(vector<int> &nums, int n){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
        for(int ind = n-1; ind>=0; ind --){
            for (int prev_index = ind-1; prev_index >=-1; prev_index --){
                
                int notTake = 0 + dp[ind+1][prev_index +1];
        
                int take = 0;
                if(prev_index == -1 || nums[ind] > nums[prev_index]){ 
                    take = 1 + dp[ind+1][ind+1];
                }
        
                dp[ind][prev_index+1] = max(notTake,take);
            }
        }
        return dp[0][0];
    }
    */

    /*
    int Space_Optimization(vector<int> &nums, int n){
        vector<int> next(n+1,0);
        vector<int> cur(n+1,0);
        
        for(int ind = n-1; ind>=0; ind --){
            for (int prev_index = ind-1; prev_index >=-1; prev_index --){
                
                int notTake = 0 + next[prev_index +1];
        
                int take = 0;
        
                if(prev_index == -1 || nums[ind] > nums[prev_index]){
                    
                    take = 1 + next[ind+1];
                }
        
                cur[prev_index+1] = max(notTake,take);
            }
            next = cur;
        }
        
        return cur[0];
    }
    */

    int Helper(vector<int> &nums, int n){
        vector<int> dp(n,1);
    
        for(int i=0; i<=n-1; i++){
            for(int prev_index = 0; prev_index <=i-1; prev_index ++){
                
                if(nums[prev_index]<nums[i]){
                    dp[i] = max(dp[i], 1 + dp[prev_index]);
                }
            }
        }
        
        int ans = -1;
        
        for(int i=0; i<=n-1; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return memorization(nums, n, 0, -1, dp);

        // return tabulation(nums, n);

        // return Space_Optimization(nums, n);

        return Helper(nums, n);
    }
};
