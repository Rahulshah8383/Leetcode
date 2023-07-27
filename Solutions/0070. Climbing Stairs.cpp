class Solution {
public:
/*  // Method 1 - NORMAL RECUSRSION T.C-->O(2^N) , Time Limit Exceeded
    int recursion(int n){
        if(n < 0){
            return 0;
        }

        if(n == 0 || n == 1){
            return 1;
        }

        int a = recursion(n-1);
        int b = recursion(n-2);

        return a+b;
    }
*/

/*  // Method 2 - memorizarion Or Top down approach(Recursion) : T.C--> O(N), S.C.-->O(N) + O(N)
    int memorisation(int n, vector<int>& dp){
        if(n < 0){
            return 0;
        }

        if(n == 0){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int left = memorisation(n-1, dp);
        int right = memorisation(n-2, dp);

        dp[n] = left + right;

        return dp[n];
    }
*/

/*
    // Method 3 - Dynamic programming or tabulation or bottom up : T.C--> O(N) & S.C.--> O(N) to store dp array
    int tabulation(int n){
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
*/

// Method 4 - space opptimization : T.C.--> O(N) & S.C -->0(1)
    int spaceOpt(int n){
        if (n == 0 || n == 1){
            return 1;
        }

        int prev1 = 1;
        int prev2 = 1;

        for(int i=2;i<=n;i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int climbStairs(int n) {
        // return recursion(n);

        // vector<int> dp(n+1, -1);
        // return memorisation(n, dp);

        // return tabulation(n);

        return spaceOpt(n);
    }
};
