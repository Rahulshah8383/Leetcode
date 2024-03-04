class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i+=3){
            int a = nums[i], b = nums[i+1], c = nums[i+2];

            if(b-a <= k && c-b <= k && c-a <= k){
                ans.push_back({a, b, c});
            }
            else{
                cout<<nums[i]<<endl;
                return {};
            }
        }

        return ans;
    }
};
