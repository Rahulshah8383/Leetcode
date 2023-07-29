class Solution {
public:
    void Helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int freq[]){
        if(temp.size() >= nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i] = 1;
                Helper(nums, ans, temp, freq);
                freq[i] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i] = 0;
        }
        Helper(nums, ans, temp, freq);
        return ans;
    }

    /*
    void Helper(vector<int>& nums, vector<vector<int>>& ans, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index;i<nums.size();i++){
            swap(nums[index], nums[i]);
            Helper(nums, ans, index+1);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        Helper(nums, ans, index);
        return ans;
    }
    */
};

