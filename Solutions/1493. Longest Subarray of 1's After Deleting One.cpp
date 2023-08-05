class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ones;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 1 ){
                sum++;
                if(i+1 > n-1){
                  ones.push_back(sum);  
                }
            }
            else{
                ones.push_back(sum);
                sum = 0;
            }
        }

        if(ones.size() == 1){
            return ones[0]-1;
        }
        
        int ans = INT_MIN;
        for(int i=0;i<ones.size()-1;i++){
            ans = max(ans, (ones[i]+ones[i+1]));
        }
        return ans;
    }
};
