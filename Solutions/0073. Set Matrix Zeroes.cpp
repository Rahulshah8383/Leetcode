class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowsize = matrix.size();
        int columnsize = matrix[0].size();
        vector<int> row(rowsize, 1);
        vector<int> column(columnsize, 1);

        for(int i=0;i<rowsize;i++){
            for(int j=0;j<columnsize;j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;
                    column[j] = 0;
                }
            }
        }

        for(int i=0;i<rowsize;i++){
            for(int j=0;j<columnsize;j++){
                if(row[i] == 0 or column[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
