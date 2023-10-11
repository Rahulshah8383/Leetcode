class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;

        for(auto& row : grid){
            sort(row.begin(), row.end());
        }
        sort(grid.begin(), grid.end());

        for(int i=0;i<m;i++){
            int max = 0;
            for(int j=0;j<n;j++){
                if(grid[j][i] > max){
                    max = grid[j][i];
                }
            }
            cout<<max<<" ";
            sum += max;
        }

        return sum;
    }
};
