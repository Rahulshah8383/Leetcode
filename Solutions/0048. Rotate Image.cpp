class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

       int l=0, h=n-1;
       while(l<h){
           swap(matrix[l], matrix[h]);
           l++; h--;
       }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
