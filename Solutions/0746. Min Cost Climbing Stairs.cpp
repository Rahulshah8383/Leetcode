class Solution {
public:
    // int recursion1(vector<int>&cost, int n,int i){
    //     if(i == n-1){
    //         return cost[i];
    //     }
    //     if(i == n-2){
    //         return cost[i];
    //     }

    //     int a = recursion(cost, n, i+1);
    //     int b = recursion(cost, n, i+2);

    //     int ans = cost[i] + min(a, b);
    //     return ans;
    // }

    // int recursion2(vector<int>&cost, int n){
    //     if(n == 0 || n == 1){
    //         return cost[n];
    //     }

    //     int ans = cost[n] + min(recursion2(cost, n-1), recursion2(cost, n-2));
    //     return ans;
    // }

    // int memorization(vector<int>& cost,int n,vector<int>& dp){
    //     if(n<=1){
    //         return cost[n];
    //     }

    //     if(dp[n] != -1){
    //         return dp[n];
    //     }

    //     int ans = cost[n] + min(memorization(cost, n-1, dp), memorization(cost, n-2, dp));

    //     dp[n] = ans;
    //     return dp[n];
    // }

    // int tabulation(vector<int> &cost, int n){
    //     vector<int> dp(n+1, -1);
    //     dp[0] = cost[0];
    //     dp[1] = cost[1];

    //     for(int i=2;i<n;i++){
    //         dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    //     }

    //     return min(dp[n-1], dp[n-2]);
    // }

    int spaceOpt(vector<int> &cost, int n){
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2;i<n;i++){
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //return min(recursion1(cost, n, 0), recursion1(cost, n, 1));

        // return min(recursion2(cost, n-1), recursion2(cost, n-2));

        // vector<int> dp(n+1, -1);
        // return min(memorization(cost, n-1, dp), memorization(cost, n-2, dp)); 

        // return tabulation(cost, n);

        return spaceOpt(cost, n);
    }
};
