class Solution {
public:
    int rec(vector<vector<int>>& grid, int row, int col, int m, int n) {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == -1) {
            return 0;
        }

        if (grid[row][col] == 2) {
            // If we reach the ending square, check if all non-obstacle squares have been visited.
            bool allVisited = true;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 0) {
                        allVisited = false;
                        break;
                    }
                }
            }
            return allVisited ? 1 : 0;
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        int count = 0;
        grid[row][col] = -1;  // Mark the square as visited.

        for (int i = 0; i < 4; i++) {
            int newRow = row + delrow[i];
            int newCol = col + delcol[i];

            count += rec(grid, newRow, newCol, m, n);
        }

        grid[row][col] = 0;  // Unmark the square.

        return count;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    return rec(grid, row, col, m, n);
                }
            }
        }

        return -1;
    }
};
