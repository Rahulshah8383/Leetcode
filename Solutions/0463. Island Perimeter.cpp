class Solution {
public:
    // void bfs(vector<vector<int>>& grid, int row, int co, vector<vector<int>>& visited){

    // }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    visited[i][j] = 1;
                    q.push({i, j});
                    break;
                    // bfs(grid, i, j, visited);
                }
            }
        }

        int ans = 0;

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, +1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int land = 0; // land aroun current land
            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                    land++;

                    if(visited[nrow][ncol] == 0){
                        q.push({nrow, ncol});
                        visited[nrow][ncol] = 1;
                    }
                }
            }

            ans += (4-land);
            // cout<<row<<" "<<col<<" "<<land<<endl;
        }

        return ans;
    }
};
