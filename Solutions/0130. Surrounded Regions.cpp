class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>> &vis){
        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board){
        int n = board.size();
        if(n == 1){
            return;
        }

        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // traverse first and last row
        for(int col=0;col<m;col++){
            //first row
            if(board[0][col] == 'O' && !vis[0][col]){
                dfs(0, col, board, vis);
            }

            //last row
            if(board[n-1][col] == 'O' && !vis[n-1][col]){
                dfs(n-1, col, board, vis);
            }
        }

        //traverse fisrt col and last col
        for(int row=0;row<n;row++){
            if(board[row][0] == 'O' && !vis[row][0]){
                dfs(row, 0, board, vis);
            }

            if(board[row][m-1] == 'O' && !vis[row][m-1]){
                dfs(row, m-1, board, vis);
            }
        }

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(board[row][col] == 'O' && !vis[row][col]){
                    board[row][col] = 'X';
                }
            }
        }

    }
};
