class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int row = grid.size() - 1;
        int col = 0;
        int totaCol = grid[0].size();

        while(row >= 0 && col < totaCol){
            if(grid[row][col] < 0){
                count += totaCol - col;
                row--;
            }
            else{
                col++;
            }
        }
        return count;
    }
};
