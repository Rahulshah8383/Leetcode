class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3){
            return 0;
        }
        int closest = nums[0] + nums[1] + nums[2];
        
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size()-2;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = nums.size()-1;

            while(left < right){
                int cursum = nums[i] + nums[left] + nums[right];
                if(abs(target-cursum) < abs(target-closest)) {
                    closest = cursum;
                }
                else if(cursum > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return closest;
    }
};
