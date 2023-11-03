class Solution {
public:
    /*
    int recursion(vector<int>& prices, int n, int ind, int buy, int cap){
        if(cap == 0){
            return 0;
        }

        if(ind == n){
            return 0;
        }

        int profit = 0;
        if(buy){
            int case1 = -prices[ind] + recursion(prices, n, ind+1, 0, cap);
            int case2 = 0 + recursion(prices, n, ind+1, 1, cap);

            profit = max(case1, case2);
        }   
        else{
            int case1 = prices[ind] + recursion(prices, n, ind+1, 1, cap-1);
            int case2 = 0 + recursion(prices, n, ind+1, 0, cap);

            profit = max(case1, case2);
        }

        return profit;
    }
    */

    /*	
    int memorization(vector<int>& prices, int n, int ind, int buy, int cap, vector<vector<vector<int>>> &dp){
        if(cap == 0){
            return 0;
        }

        if(ind == n){
            return 0;
        }

        if(dp[ind][buy][cap] != -1){
            return dp[ind][buy][cap];
        }

        int profit = 0;
        if(buy){
            int case1 = -prices[ind] + memorization(prices, n, ind+1, 0, cap, dp);
            int case2 = 0 + memorization(prices, n, ind+1, 1, cap, dp);

            profit = max(case1, case2);
        }   
        else{
            int case1 = prices[ind] + memorization(prices, n, ind+1, 1, cap-1, dp);
            int case2 = 0 + memorization(prices, n, ind+1, 0, cap, dp);

            profit = max(case1, case2);
        }

        return dp[ind][buy][cap] = profit;
    }
    */

    /*
    int tabular(vector<int>& prices, int n){
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int ind = n - 1 ; ind >= 0; ind--){
            for(int buy = 0 ; buy <= 1; buy++){
                for (int cap = 1; cap <= 2; cap++) {
                    int profit = 0;
                    if(buy){
                        int case1 = -prices[ind] + dp[ind+1][0][cap];
                        int case2 = 0 + dp[ind+1][1][cap];

                        profit = max(case1, case2);
                    }   
                    else{
                        int case1 = prices[ind] + dp[ind+1][1][cap-1];
                        int case2 = 0 + dp[ind+1][0][cap];

                        profit = max(case1, case2);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
    */

    int SpaceOp(vector<int>& prices, int n){
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 0) { // We can buy the stock
                        curr[buy][cap] = max(0 + ahead[0][cap], 
                                            -prices[ind] + ahead[1][cap]);
                    }

                    if (buy == 1) { // We can sell the stock
                        curr[buy][cap] = max(0 + ahead[1][cap],
                                            prices[ind] + ahead[0][cap - 1]);
                    }
                }
            }
            // Update the ahead state with the current state for the next iteration.
            ahead = curr;
        }

        return ahead[0][2];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // return recursion(prices, n, 0, 1, 2);

        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return memorization(prices, n, 0, 1, 2, dp);

        // return tabular(prices, n);

        return SpaceOp(prices, n);
    }
};
