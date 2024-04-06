class Solution {
public:
    /*
    int numEnclaves(vector<vector<int>>& grid) {
       queue<pair<int,int>> q; 
    
        int n = grid.size(); 
        int m = grid[0].size(); 

        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        
        // traverse boundary elements
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // first row, first col, last row, last col 
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    // if it is a land then store it in the queue
                    if(grid[i][j] == 1) {
                        q.push({i, j}); 
                        vis[i][j] = 1; 
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1}; 
        
        while(!q.empty()) {
            int row = q.front().first; 
            int col = q.front().second; 
            q.pop(); 
            
            // traverses all 4 directions
            for(int i = 0;i<4;i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i]; 
                // check for valid coordinates and for land cell
                if(nrow >=0 && nrow <n && ncol >=0 && ncol < m 
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1; 
                }
            }
            
        }
        
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // check for unvisited land cell
                if(grid[i][j] == 1 && vis[i][j] == 0) 
                    cnt++; 
            }
        }
        return cnt;
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
