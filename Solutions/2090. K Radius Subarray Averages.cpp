class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> ans(size, -1);
        long long sum = 0;
        
        for(int i=0;i<size;i++){
            if(i < 2*k)
                sum += nums[i];
            else{
                sum += nums[i];
                ans[i-k] = sum/(2*k+1);
                sum = sum - nums[i-(2*k)];
            }
        }
        return ans;
    }
};
