class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited, int n, int m){
        visited[row][col] = 1;

        int delRow[] = {-1, 0, 0, +1};
        int delCol[] = {0, -1, +1, 0};

        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && !visited[nrow][ncol]){
                dfs(nrow, ncol, board, visited, n, m);
            }
        }
    }

    void bfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited, int n, int m){
        visited[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        int delRow[] = {-1, 0, 0, +1};
        int delCol[] = {0, -1, +1, 0};

        while(!q.empty()){
            int irow = q.front().first;
            int icol = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = irow + delRow[i];
                int ncol = icol + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
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
                // dfs(0, col, board, vis, n, m);
                bfs(0, col, board, vis, n, m);
            }

            //last row
            if(board[n-1][col] == 'O' && !vis[n-1][col]){
                // dfs(n-1, col, board, vis, n, m);
                bfs(n-1, col, board, vis, n, m);
            }
        }

        //traverse fisrt col and last col
        for(int row=0;row<n;row++){
            if(board[row][0] == 'O' && !vis[row][0]){
                // dfs(row, 0, board, vis, n, m);
                bfs(row, 0, board, vis, n, m);
            }

            if(board[row][m-1] == 'O' && !vis[row][m-1]){
                // dfs(row, m-1, board, vis, n, m);
                bfs(row, m-1, board, vis, n, m);
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
