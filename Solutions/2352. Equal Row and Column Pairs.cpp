class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = grid.size();
        int count = 0;
        vector<int> row;
        for(int i=0;i<n;i++){
            row = grid[i];
            for(int j=0;j<n;j++){
                vector<int> col;
                for(int k=0;k<n;k++){
                    col.push_back(grid[k][j]);
                }
                if(row == col){
                    count++;
                }
            }
        }
        return count;
    }
};
