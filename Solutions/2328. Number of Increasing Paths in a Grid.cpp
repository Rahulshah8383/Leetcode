class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][1001];

    int solver(vector<vector<int>>& grid,int i,int j,int prev){
        int m = grid.size(), n = grid[0].size();

        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] <= prev){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int up = solver(grid, i-1, j, grid[i][j]);
        int down = solver(grid, i+1, j, grid[i][j]);
        int left = solver(grid, i, j-1, grid[i][j]);
        int right = solver(grid, i, j+1, grid[i][j]);

        return dp[i][j] = (1 + up + down + left + right)%mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = (ans + solver(grid, i, j, -1))%mod;
            }
        }
        return ans;
    }
};
