class Solution {
public:
    /*
    int recursion(vector<int>& coins, int amount, int ind){
        if(ind == 0){
            if(amount % coins[0] == 0){
                return amount / coins[0];
            }
            else{
                return 1e9;
            }
        }

        int notTake = 0 + recursion(coins, amount, ind-1);
        int take = 1e9;
        if(coins[ind] <= amount){
            take = 1 + recursion(coins, amount-coins[ind], ind);
        }

        return min(notTake, take);
    }
    */

    /*
    int memorization(vector<int>& coins, int amount, int ind, vector<vector<int>> &dp){
        if(ind == 0){
            if(amount % coins[0] == 0){
                return amount / coins[0];
            }
            else{
                return 1e9;
            }
        }

        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }

        int notTake = 0 + memorization(coins, amount, ind-1, dp);
        int take = 1e9;
        if(coins[ind] <= amount){
            take = 1 + memorization(coins, amount-coins[ind], ind, dp);
        }

        return dp[ind][amount] = min(notTake, take);
    }
    */

    /*
    int tabular(vector<int>& coins, int amount) {
        int n = coins.size();
        
        // Create a 2D DP (Dynamic Programming) table with n rows and amount+1 columns
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        
        // Initialize the first row of the DP table
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9; // Set it to a very large value if not possible
        }
        
        // Fill the DP table using a bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                // Calculate the minimum elements needed without taking the current element
                int notTake = dp[ind - 1][target];
                
                // Calculate the minimum elements needed by taking the current element
                int take = 1e9; // Initialize 'take' to a very large value
                if (coins[ind] <= target)
                    take = 1 + dp[ind][target - coins[ind]];
                    
                // Store the minimum of 'notTake' and 'take' in the DP table
                dp[ind][target] = min(notTake, take);
            }
        }
        
        // The answer is in the bottom-right cell of the DP table
        int ans = dp[n - 1][amount];
        
        // If 'ans' is still very large, it means it's not possible to form the target sum
        if (ans >= 1e9)
            return -1;
        
        return ans; // Return the minimum number of elements needed
    }
    */

    int SpaceOp(vector<int>& coins, int amount) {
        int n = coins.size();
        
        // Create two vectors to store the previous and current DP states
        vector<int> prev(amount + 1, 0);
        vector<int> cur(amount + 1, 0);
        
        // Initialize the first row of the DP table
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = 1e9; // Set it to a very large value if not possible
        }
        
        // Fill the DP table using a bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                // Calculate the minimum elements needed without taking the current element
                int notTake = prev[target];
                
                // Calculate the minimum elements needed by taking the current element
                int take = 1e9; // Initialize 'take' to a very large value
                if (coins[ind] <= target)
                    take = 1 + cur[target - coins[ind]];
                    
                // Store the minimum of 'notTake' and 'take' in the current DP state
                cur[target] = min(notTake, take);
            }
            // Update the previous DP state with the current state for the next iteration
            prev = cur;
        }
        
        // The answer is in the last row of the DP table
        int ans = prev[amount];
        
        // If 'ans' is still very large, it means it's not possible to form the target sum
        if (ans >= 1e9)
            return -1;
        
        return ans; // Return the minimum number of elements needed
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int ans =  recursion(coins, amount, n-1);

        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = memorization(coins, amount, n-1, dp);

        // int ans = tabular(coins, amount);

        int ans = SpaceOp(coins, amount);

        if(ans >= 1e9)
            return -1;
        return ans;
    }
};  
