class Solution {
public:
/*
    int recursion(string &text1, string &text2, int i, int j){
        // Base case: If either string reaches the end, return 0
        if(i<0 || j<0){
            return 0;
        }

        // If the characters at the current indices match, increment the LCS length
        if(text1[i] == text2[j]){
            return 1 + recursion(text1, text2, i-1, j-1);
        }

        // If the characters don't match, consider two options: moving either left or up in the strings
        int case1 = recursion(text1, text2, i-1, j);
        int case2 = recursion(text1, text2, i, j-1);

        return max(case1, case2);
    }
    */

    /*
    int memorization(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        // Base case: If either string reaches the end, return 0
        if(i<0 || j<0){
            return 0;
        }

        // If the result for this pair of indices is already calculated, return it
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // If the characters at the current indices match, increment the LCS length
        if(text1[i] == text2[j]){
            return 1 + memorization(text1, text2, i-1, j-1, dp);
        }

        // If the characters don't match, consider two options: moving either left or up in the strings
        int case1 = memorization(text1, text2, i-1, j, dp);
        int case2 = memorization(text1, text2, i, j-1, dp);

        return dp[i][j] = max(case1, case2);
    }
    */

    // we set the base case to if(ind1<0 || ind2<0) but we can’t set the dp array’s index to -1. Therefore a hack for this issue is to shift every index by 1 towards the right.
    // Recursive code indexes : -1, 0, 1,.........n
    // Shifted indexes : -0, 1,.........n-1
    
    /*
    int memorization(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        // Base case: If either string reaches the end, return 0
        if(i==0 || j==0){
            return 0;
        }

        // If the result for this pair of indices is already calculated, return it
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // If the characters at the current indices match, increment the LCS length
        if(text1[i-1] == text2[j-1]){
            return 1 + memorization(text1, text2, i-1, j-1, dp);
        }

        // If the characters don't match, consider two options: moving either left or up in the strings
        int case1 = memorization(text1, text2, i-1, j, dp);
        int case2 = memorization(text1, text2, i, j-1, dp);

        return dp[i][j] = max(case1, case2);
    }
    */

    /*
    int tabular(string text1, string text2, int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Base case
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }

        for(int j=0;j<=m;j++){
            dp[0][j] = 0;
        }

        // Fill in the DP table to calculate the length of LCS
        for(int i = 1;i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];  // Characters match, increment LCS length
                }
                else{
                    int case1 = dp[i-1][j];
                    int case2 = dp[i][j-1];

                    dp[i][j] = max(case1, case2);  // Characters don't match, consider the maximum from left or above
                }
            }
        }

        return dp[n][m]; // Return the length of the Longest Common Subsequence
    }
    */

    int SpaceOp(string text1, string text2, int n, int m){
        // Initialize two vectors to store the current and previous rows of the DP table
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        // Base case is covered as we have initialized the prev and cur vectors to 0.
        for(int i = 1;i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1 + prev[j-1]; // Characters match, increment LCS length
                }
                else{
                    int case1 = prev[j];
                    int case2 = curr[j-1];

                    curr[j] = max(case1, case2); // Characters don't match, consider the maximum from above or left
                }
            }
            prev = curr; // Update the previous row with the current row
        }

        return prev[m]; // Return the length of the Longest Common Subsequence
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // return recursion(text1, text2, n-1, m-1);

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return memorization(text1, text2, n-1, m-1, dp);

        // After shifter indexes
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return memorization(text1, text2, n, m, dp);

        // return tabular(text1, text2, n, m);

        return SpaceOp(text1, text2, n, m);
    }
};
