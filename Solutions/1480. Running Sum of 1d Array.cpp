class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        
        for(int i=0;i<size;i++){
            int j = 0, sum = 0;
            while(j<=i){
                sum = sum + nums[j++];
            }
            ans.push_back(sum);
        }

        return ans;
    }
};
