class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int s_row = 0, s_col = 0, e_row = row-1, e_col = col-1;
        int size = row*col;
        while(ans.size() != size){
            for(int i=s_row;i<=e_col && ans.size() != size; i++){
                ans.push_back(matrix[s_row][i]);
            }
            s_row++;

            for(int i=s_row;i<=e_row && ans.size() != size; i++){
                ans.push_back(matrix[i][e_col]);
            }
            e_col--;

            for(int i=e_col;i>=s_col && ans.size() != size; i--){
                ans.push_back(matrix[e_row][i]);
            }
            e_row--;

            for(int i=e_row;i>=s_row && ans.size() != size; i--){
                ans.push_back(matrix[i][s_col]);
            }
            s_col++;
        }
        return ans;
    }
};
