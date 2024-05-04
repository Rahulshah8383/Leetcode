class Solution {
public:
    int n, m;
    vector<vector<int>> result;
    int delRow[4] = {-1, 0, 0, +1};
    int delCol[4] = {0, -1, +1, 0};

    void dfs(vector<vector<int>>& land, int r1, int c1, int &r2, int &c2){
        land[r1][c1] = 0;

        r2 = max(r1, r2);
        c2 = max(c1, c2);

        for(int i=0;i<4;i++){
            int row = delRow[i] + r1;
            int col = delCol[i] + c1;

            if(row >= 0 && row < n && col >= 0 && col < m && land[row][col] == 1){
                dfs(land, row, col, r2, c2);
            }
        }
    }

    void bfs(vector<vector<int>>& land, int r1, int c1, int &r2, int &c2){
        queue<pair<int, int>> q;
        q.push({r1, c1});

        while(!q.empty()) {
            int Row = q.front().first;
            int Col = q.front().second;
            q.pop();

            r2 = max(Row, r2);
            c2 = max(Col, c2);

            for(int i=0;i<4;i++){
                int row = delRow[i] + Row;
                int col = delCol[i] + Col;

                if(row >= 0 && row < n && col >= 0 && col < m && land[row][col] == 1){
                    land[row][col] = 0;
                    q.push({row, col});
                }
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] == 1){
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;

                    // Approach 1: O(m*n), O(1)
                    // dfs(land, r1, c1, r2, c2);
                    
                    // Approach 2: O(m*n), O(m*n)
                    bfs(land, r1, c1, r2, c2);

                    result.push_back({r1, c1, r2, c2});
                }
            }
        }

        return result;
    }
};
