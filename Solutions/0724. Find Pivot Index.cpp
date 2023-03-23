class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int Total= 0, left_Sum = 0;

        for(auto i: nums){
            Total = Total + i;
        }  

        for(int i=0;i<nums.size();i++){
            if(left_Sum == Total - left_Sum - nums[i])
                return i;
            left_Sum = left_Sum + nums[i];
        }
        return -1;
    }
};
