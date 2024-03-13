class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        int subset_ct = (1<<n);
        vector<vector<int>> subsets;

        for(int mask=0;mask<subset_ct;mask++){
            vector<int> subset;
            for(int i=0;i<n;i++){
                if((mask & (1<<i)) != 0){
                    subset.push_back(nums[i]);
                }
            }
            subsets.push_back(subset);
        }
        
        int ans = 0;
        for(int i=0;i<subsets.size();i++){
            int t_sum = 0;
            for(int j=0;j<subsets[i].size();j++){
                t_sum = t_sum^subsets[i][j];
            }
            ans += t_sum;
        }
        return ans;
    }
};
