class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, row = matrix.size()-1;
        int j = matrix[0].size()-1;

        while(i <= row && j>=0){
            if(matrix[i][j] == target){
                return true;
            }

            else if(matrix[i][j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
