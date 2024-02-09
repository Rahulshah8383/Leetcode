class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int i = INT_MAX, j = INT_MAX, k = INT_MIN;

        for(int idx=0;idx<n;idx++){
            
           i = min(i, nums[idx]);
           if(i < nums[idx]){
               j = min(j, nums[idx]);
           }
           if(j < nums[idx]){
               k = max(k, nums[idx]);
           }
           if(i<j && j<k){
               return true;
           }
        }  

        return false; 
    }
};
