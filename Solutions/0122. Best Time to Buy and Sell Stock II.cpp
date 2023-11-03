class Solution {
public:
    /*
    int recursion(vector<int>& prices, int n, int ind, int buy){
        if(ind == n){
            return 0;
        }

        int profit = 0;
        if(buy){
            int case1 = -prices[ind] + recursion(prices, n, ind+1, 0);
            int case2 = 0 + recursion(prices, n, ind+1, 1);

            profit = max(case1, case2);
        }   
        else{
            int case1 = prices[ind] + recursion(prices, n, ind+1, 1);
            int case2 = 0 + recursion(prices, n, ind+1, 0);

            profit = max(case1, case2);
        }

        return profit;
    }
    */

    /*
    int memorization(vector<int>& prices, int n, int ind, int buy, vector<vector<int>> &dp){
         if(ind == n){
            return 0;
        }

        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }

        int profit = 0;
        if(buy){
            int case1 = -prices[ind] + memorization(prices, n, ind+1, 0, dp);
            int case2 = 0 + memorization(prices, n, ind+1, 1, dp);

            profit = max(case1, case2);
        }   
        else{
            int case1 = prices[ind] + memorization(prices, n, ind+1, 1, dp);
            int case2 = 0 + memorization(prices, n, ind+1, 0, dp);

            profit = max(case1, case2);
        }

        return dp[ind][buy] = profit;
    }
    */

    /*
    int tabular(vector<int>& prices, int n){
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int ind = n - 1 ; ind >= 0; ind--){
            for(int buy = 0 ; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    int case1 = -prices[ind] + dp[ind+1][0];
                    int case2 = 0 + dp[ind+1][1];

                    profit = max(case1, case2);
                }   
                else{
                    int case1 = prices[ind] + dp[ind+1][1];
                    int case2 = 0 + dp[ind+1][0];

                    profit = max(case1, case2);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }
    */

    /*
    int SpaceOp(vector<int>& prices, int n){
        // Create two array to store the profirs ahead of the current postion (0 for not holding , 1 for holding)
        vector<int> ahead(2, 0);
        vector<int> curr(2, 0);

        // Base condition: When there are no stocks left. the profit it 0.
        ahead[0] = 0;
        ahead[1] = 0;

        // Loop throught the array in reverse order
        for(int ind = n - 1 ; ind >= 0; ind--){
            for(int buy = 0 ; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    int case1 = -prices[ind] + ahead[0];
                    int case2 = 0 + ahead[1];

                    profit = max(case1, case2);
                }   
                else{
                    int case1 = prices[ind] + ahead[1];
                    int case2 = 0 + ahead[0];

                    profit = max(case1, case2);
                }
               curr[buy] = profit;
            }
            ahead = curr;
        }

        return ahead[1];
    }
    */

    int SpaceOp(vector<int>& prices, int n){
        // Create two arrays to store the profits ahead of the current position (0 for not holding, 1 for holding)
        vector<int> ahead(2, 0);
        vector<int> curr(2, 0);

        // Base condition: When there are no stocks left, the profit is 0.
        ahead[0] = ahead[1] = 0;

        long profit;

        // Loop through the array in reverse order
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0) { // We can buy the stock
                    profit = max(0 + ahead[0], -prices[ind] + ahead[1]);
                }

                if (buy == 1) { // We can sell the stock
                    profit = max(0 + ahead[1], prices[ind] + ahead[0]);
                }
                curr[buy] = profit;
            }

            ahead = curr; // Update the "ahead" array with the current values
        }

        // The maximum profit is stored in cur[0] after all calculations
        return curr[0];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // return recursion(prices, n, 0, 1);

        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return memorization(prices, n, 0, 1, dp);

        // return tabular(prices, n);

        return SpaceOp(prices, n);
    }
};
