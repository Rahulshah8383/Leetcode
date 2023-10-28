class Solution {
public:
    /*
    int recursion(vector<vector<int>>& matrix, int row, int col, int m){
        if(col < 0 || col >= m){
            return 1e9; // A very large negative value to represetn an invalid path
        }

        if(row == 0){
            return matrix[row][col]; // The maximum path sum for the top row is the value itself
        }

        // Calculate the maximum path sum by considering three possible directions: up, left diagonal, and right diagonal
        int up = matrix[row][col] + recursion(matrix, row-1, col, m);
        int leftDiagonal = matrix[row][col] + recursion(matrix, row-1, col-1, m);
        int rightDiagonal = matrix[row][col] + recursion(matrix, row-1, col+1, m);
        
        return min({up, leftDiagonal, rightDiagonal});
    }
    */

    /*
    int memorization(vector<vector<int>>& matrix, int row, int col, int m, vector<vector<int>> &dp){
        if(col < 0 || col >= m){
            return 1e9; // A very large negative value to represetn an invalid path
        }

        if(row == 0){
            return matrix[row][col]; // The maximum path sum for the top row is the value itself
        }

        // // If the result for this cell is already calculated, return it
        if(dp[row][col] != -1){
            return dp[row][col];
        }

        // Calculate the maximum path sum by considering three possible directions: up, left diagonal, and right diagonal
        int up = matrix[row][col] + memorization(matrix, row-1, col, m, dp);
        int leftDiagonal = matrix[row][col] + memorization(matrix, row-1, col-1, m, dp);
        int rightDiagonal = matrix[row][col] + memorization(matrix, row-1, col+1, m, dp);
        
        // Store the maximum of the three paths in dp
        dp[row][col] =  min({up, leftDiagonal, rightDiagonal});
        return dp[row][col];
    }
    */

    /*
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of row in the matrix
        int m = matrix[0].size(); // Number of columns in the matrix

        int ans = INT_MAX; // Initialize the minimum path sum to a very small value

         //vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int col=0;col<m;col++){
            //int temp = recursion(matrix, n-1, col, m);

            int temp = memorization(matrix, n-1, col, m, dp);
            ans = min(ans, temp);
        }
        
        return ans;
    }
    */

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                
                int leftDiagonal=1e9, rightDiagonal = 1e9;
                
                int up = matrix[i][j] + dp[i-1][j];
                
                if(j-1>=0)
                    leftDiagonal = matrix[i][j] + dp[i-1][j-1];
                if(j+1<m)
                    rightDiagonal = matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }
        
        int mini=dp[n-1][0];

        for(int j=1;j<m;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};
