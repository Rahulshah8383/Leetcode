class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss = 0;

        for (int i = 0; i < nums.size(); i ++) {
            miss = miss ^ i + 1;
            miss = miss ^ nums[i];
        }

        return miss;
    }
};
