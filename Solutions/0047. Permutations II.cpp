class Solution {
public:
    void Helper(vector<int>& nums, set<vector<int>> &ans, int index){
        if(index >= nums.size()){
            ans.insert(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index], nums[i]);
            Helper(nums, ans, index+1);
            // Backtrack
           swap(nums[index], nums[i]); 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        Helper(nums, ans, 0);

        vector<vector<int>> res(ans.begin(), ans.end());

        // for (const vector<int>& permutation : res) {
        //     for (int num : permutation) {
        //         cout << num << " ";
        //     }
        //     cout << endl;
        // }

        return res;
    }
};
