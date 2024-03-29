class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto it : mp){
            int t = it.second;
            if(t==1)
                return -1;
            ans += t/3;
            if(t%3) ans++;
        }

        return ans;
    }
};
