class Solution {
public:
    /*
    int recursion(vector<vector<int>>& triangle, int i, int j, int n, vector<vector<int>> dp) {
        
        // if we'are at the bottom row, return the value of current cell
        if(i == n-1){
            return triangle[i][j];
        }

        // Calculate the sum of two possible paths: going down and goind diagonally
        int down = triangle[i][j] + recursion(triangle, i+1, j, n, dp);
        int diagonal = triangle[i][j] + recursion(triangle, i+1, j+1, n, dp);

        return min(down, diagonal);
    }
    */

    /*
    // Time Complexity: O(N*N), Space Complexity: O(N*N)

    int memorization(vector<vector<int>>& triangle, int i, int j, int n, vector<vector<int>> &dp) {
        // if we'are at the bottom row, return the value of current cell
        if(i == n-1){
            return triangle[i][j];
        }

        // if the result for this cell is already calculated, return it
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // Calculate the sum of two possible paths: going down and goind diagonally
        int down = triangle[i][j] + memorization(triangle, i+1, j, n, dp);
        int diagonal = triangle[i][j] + memorization(triangle, i+1, j+1, n, dp);

        // Store the minimum of the two paths in the dp table and return it
        dp[i][j] = min(down, diagonal);
        return dp[i][j];
    }
    */

    /*
    // Time Complexity: O(N*N), Space Complexity: O(N*N)
    int tabular(vector<vector<int>>& triangle, int n){
        // Create a 2D DP (dynamic programming) array to store minimum path sums
        vector<vector<int> > dp(n, vector<int>(n, 0));

        // Initialize the bottom row of dp with the values from the triangle
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Iterate through the triangle rows in reverse order
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                // Calculate the minimum path sum for the current cell
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];

                // Store the minimum of the two possible paths in dp
                dp[i][j] = min(down, diagonal);
            }
        }

        // The top-left cell of dp now contains the minimum path sum
        return dp[0][0];
    }
    */

    // Time Complexity: O(N*N), Space Complexity: O(N)

    int SpaceOP(vector<vector<int>>& triangle, int n){
        // Create two arrays to store the current and previous row values
        vector<int> front(n, 0); // Represents the previous row
        vector<int> curr(n, 0);   // Represents the current row
        
        // Initialize the front array with values from the last row of the triangle
        for (int j = 0; j < n; j++) {
            front[j] = triangle[n - 1][j];
        }
        
        // Iterate through the triangle rows in reverse order
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                // Calculate the minimum path sum for the current cell
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j + 1];
                
                // Store the minimum of the two possible paths in the current row
                curr[j] = min(down, diagonal);
            }
            // Update the front array with the values from the current row
            front = curr;
        }
        
        // The front array now contains the minimum path sum from the top to the bottom of the triangle
        return front[0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // return Helper(triangle, 0, 0, n, dp);

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return memorization(triangle, 0, 0, n, dp);

        // return tabular(triangle, n);

        return SpaceOP(triangle, n);
    }
};
