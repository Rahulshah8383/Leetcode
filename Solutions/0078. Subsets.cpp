class Solution {
private:
    /*
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> >& ans) {
        //base case
        if(index >= nums.size()) {
            ans.push_back(output);
            return ;
        }
        
        //exclude
        solve(nums, output, index+1, ans);
        
        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
    }
   */

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, output, 0, ans);
        return ans;
        */

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
        return subsets;
    }
};
