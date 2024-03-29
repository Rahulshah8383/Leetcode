class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        const int m = nums.size();
        int l = 0, r = m-1;
        while(l<r){
            if(nums[l]+nums[r]==k){
                ans+=1;
                ++l;--r;
            }
            else if(nums[l]+nums[r]>k){--r;}
            else{++l;}
        }
        return ans;
    }
};
