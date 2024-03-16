class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive, negative;

        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0){
                positive.push_back(nums[i]);
            }
            else{
                negative.push_back(nums[i]);
            }
        }

        int k = 0;
        for(int i=0;i<positive.size();i++){
            nums[k++] = positive[i];
            nums[k++] = negative[i];
        }

        return nums;
    }
};
