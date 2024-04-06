class Solution {
public:
    /*
    bool isValid(int i, int j, int n, int m, vector<vector<char>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1'){
            return true;
        }
        return false;
    }

    void Helper(int i, int j, int n, int m, vector<vector<char>>& grid){
        grid[i][j] = 0;

        if(isValid(i+1, j, n, m, grid))
            Helper(i+1, j, n, m, grid);

        if(isValid(i-1, j, n, m, grid))
            Helper(i-1, j, n, m, grid);

        if(isValid(i, j+1, n, m, grid))
            Helper(i, j+1, n, m, grid);

        if(isValid(i, j-1, n, m, grid))
            Helper(i, j-1, n, m, grid);
    }

    int numIslands(vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    Helper(i, j, n, m, grid);
                }
            }
        }
        return ans;
    }
    */

void BFS(vector<vector<char>>& grid, vector<vector<int>> &visited, int row, int col, int n, int m){
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int delRow[] = {-1, 0, 0, +1};
        int delCol[] = {0, -1, +1, 0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid.size();

        vector<vector<int>> visited(n, vector<int> (m, 0));
        int ans = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col] == '1' && !visited[row][col]){
                    BFS(grid, visited, row, col, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};
