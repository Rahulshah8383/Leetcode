class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        vector<long long> res;
        int k_max = 0;
        
        for(int i=0;i<nums.size();i++){
            k_max = max(k_max, nums[i]);
            long long sum = nums[i] + k_max;
            res.push_back(sum);
        }
        
        long long sum = 0;
        for(int i=0;i<res.size();i++){
            sum = sum + res[i];
            ans.push_back(sum);
        }
        return ans;
    }
};
