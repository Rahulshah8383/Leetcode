class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));

        int delrow[] = {-1, -1, -1, 0, 0, +1, +1, +1};
        int delcol[] = {-1, 0, +1, -1, +1, -1, 0, +1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum = img[i][j];
                int filter_size = 1;

                for(int k=0;k<8;k++){
                    int row = i + delrow[k];
                    int col = j + delcol[k];

                    if(row >= 0 && row < n && col >= 0 && col < m){
                        sum += img[row][col];
                        filter_size++;
                    }
                }

                ans[i][j] = floor(sum/filter_size);
            }
        }

        return ans;
    }
};
