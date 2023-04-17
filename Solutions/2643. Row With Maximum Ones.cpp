class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int idx=0, ones=0;
        
        for(int i=0;i<mat.size();i++){
            int temp_idx=i, temp_ones=0;
            for(int j=0;j<mat[0].size();j++){
                int k = mat[i][j];
                
                if(k == 1){
                    temp_ones++;
                }
            }
            if(ones < temp_ones){
                idx = temp_idx;
                ones = temp_ones;
            }
        }
        ans.push_back(idx);
        ans.push_back(ones);
        return ans;
    }
};
