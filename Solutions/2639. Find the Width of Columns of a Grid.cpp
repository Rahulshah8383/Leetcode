class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), 0));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int num = grid[i][j];
                
                int digit = 0;
                int n = abs(num);
                while(n > 0){
                    digit += 1;
                    n /= 10;
                }
                
                if(num <= 0){
                    digit += 1;
                }
                
                res[i][j] = digit;
            }
        }
        
        for (int i = 0; i < res[0].size(); i++){
            int k = 0;
            for (int j = 0; j < res.size(); j++){
                k = max(k, res[j][i]);
            }
            ans.push_back(k);
        }
        
        return ans;
    }
};
