class Solution {
public:
    /*
    int recursion(int i, int j){
        if(i==0 && j==0){
            return 1;
        }

        if(i < 0 || j < 0){
            return 0;
        }

        int up = recursion(i-1, j);
        int left = recursion(i, j-1);
        return up+left;
    }
    */

    /*
    int memorization(int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0){
            return 1;
        }
        
        if(i < 0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1)
            return dp[i][j];
        int up = memorization(i-1, j, dp);
        int left = memorization(i, j-1, dp);
        dp[i][j] = up+left;

        return dp[i][j];
    }
    */

    int tabular(int m, int n){
        vector<vector<int> > dp(m,vector<int>(n,-1));
        for(int i=0; i<m ;i++){
            for(int j=0; j<n; j++){
                
                //base condition
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                
                int up=0;
                int left = 0;
                
                if(i>0) 
                    up = dp[i-1][j];
                if(j>0)
                    left = dp[i][j-1];
                    
                dp[i][j] = up+left;
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePaths(int m, int n) {
        // return recursion(m-1, n-1);

        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return memorization(m-1, n-1, dp);

        return tabular(m, n);
    }
};
