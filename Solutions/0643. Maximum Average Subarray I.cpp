class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    int max_sum = INT_MIN, sum = 0;
    int i = 0, j = 0, n = nums.size();

    while (j < n) {
        sum = sum + nums[j];

        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            max_sum = max(max_sum, sum);
            sum = sum - nums[i];
            j++; i++;
        }
    }

    return (double)max_sum/k;
    }
};
