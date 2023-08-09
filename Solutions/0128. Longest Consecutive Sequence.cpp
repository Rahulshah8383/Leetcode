class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> s;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(s.empty() || (s.find(nums[i]-1) != s.end())){
                s.insert(nums[i]);
            }
            else{
                s.clear();
                s.insert(nums[i]);

            }
            if(s.size() > ans){
                ans = s.size();
            }
        }

        return ans;
    }
};
