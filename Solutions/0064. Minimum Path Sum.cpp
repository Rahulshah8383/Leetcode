class Solution {
public:
    /*
    int recursion(vector<vector<int>>& grid, int i, int j){
        if(i == 0 && j == 0){
            return grid[0][0];
        }

        if(i<0 || j<0){
            return 1e9;
        }

        int up = grid[i][j] + recursion(grid, i-1, j);
        int left = grid[i][j] + recursion(grid, i, j-1);

        return min(up, left);
    }
    */

    /*
    int memorization(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){
        if(i== 0 && j==0){
            return grid[0][0];
        }

        if(i<0 || j<0){
            return 1e9;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int up = grid[i][j] + memorization(grid, i-1, j, dp);
        int left = grid[i][j] + memorization(grid, i, j-1, dp);

        dp[i][j] = min(up, left);

        return dp[i][j];
    }
    */

    /*
    int tabulation(vector<vector<int>>& grid, int n, int m){
        vector<vector<int> > dp(n,vector<int>(m,0));
        for(int i=0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    
                    int up = grid[i][j];
                    if(i>0) up += dp[i-1][j];
                    else up += 1e9;
                    
                    int left = grid[i][j];
                    if(j>0) left+=dp[i][j-1];
                    else left += 1e9;
                    
                    dp[i][j] = min(up,left);
                }
            }
        }
        
        return dp[n-1][m-1];
    }
    */

    int Space_Optimization(vector<vector<int>>& grid, int n, int m){
        vector<int> prev(m,0);

        for(int i=0; i<n ; i++){
            vector<int> temp(m,0);
            for(int j=0; j<m; j++){
                if(i==0 && j==0) 
                    temp[j] = grid[i][j];
                else{
                    
                    int up = grid[i][j];
                    if(i>0) up += prev[j];
                    else up += 1e9;
                    
                    int left = grid[i][j];
                    if(j>0) left+=temp[j-1];
                    else left += 1e9;
                    
                    temp[j] = min(up,left);
                }
            }
            prev=temp;
        }
        
        return prev[m-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // return recursion(grid, n-1, m-1);
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return memorization(grid, n-1, m-1, dp);

        // return tabulation(grid, n, m);

        return Space_Optimization(grid, n, m);
    }
};
