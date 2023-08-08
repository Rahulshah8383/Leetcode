class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        int m = matrix.size();
        int n = matrix[0].size();

        if(m==0 || n == 0){
            return false;
        }

        int start = matrix[0][0];
        int end = matrix[m-1][n-1];

        while(start <= end){
            int mid = start + (end - start)/2;
            int row = 0;
            int col = n-1;

            while(row < m && col >=0){
                if(matrix[row][col] == target)
                    return true;
                else if(matrix[row][col] < target)
                    row++;
                else
                    col--; 
            }

            if(row == m)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
        */
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end  = row*col-1;
        
        int mid = start + (end-start)/2;
        
        while(start<=end) {
            
            int element = matrix[mid/col][mid%col];
            
            if(element == target) {
                return 1;
            }
            
            if(element < target) {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
             mid = start + (end-start)/2;    
        }
        return 0;
    }
};
