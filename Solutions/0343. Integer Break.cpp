class Solution {
public:
    /*
    int Memoization(int n, vector<int> &dp)
        {
            if (n == 1) return 1;
           	//BASE CASE
            if (dp[n] != -1) return dp[n];
           	//Already solved
            int ans = n;
           	//Could be INT_MIN also
            for (int i = 1; i <= n / 2; i++)
            {
                ans = max(ans, i* Memoization(n - i, dp));
               	//Finding max among sets
            }
            return dp[n] = ans;
           	//Storing the max val
        }

    int integerBreak(int n) {
        if (n < 4) return n - 1;
       	//Precalculated
        vector<int> dp(n + 1, -1);
       	//As only one param is changing
        return Memoization(n, dp);
    }
    */

    int integerBreak(int n) {
        if (n < 4) return n - 1;
        vector<int> dp(n + 1, -1);
       	
        dp[0] = 1;
        dp[1] = 1;

       for(int i=1;i<=n;i++){
           for(int j=1;j<=i;j++){
               dp[i] = max(dp[i], j*dp[i-j]);
           }
        }
        return dp[n];
    }
};
