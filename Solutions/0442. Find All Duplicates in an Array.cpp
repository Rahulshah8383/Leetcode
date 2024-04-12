class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;

        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) != mp.end()){
                ans.push_back(nums[i]);
            }
            else{
                mp[nums[i]]++;
            }
        }

        return ans;
    }
};
