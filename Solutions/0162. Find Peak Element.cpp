class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int maxElement = INT_MIN;  // Change 'ans' to 'maxElement'

        while (s <= e) {
            if (nums[s] == nums[e]) {
                maxElement = max(maxElement, nums[s]);
                s++;
                e--;
            } else if (nums[s] > nums[e]) {
                maxElement = max(maxElement, nums[s]);
                e--;
            } else {
                maxElement = max(maxElement, nums[e]);
                s++;
            }
            cout << maxElement << " ";
        }

        auto it = find(nums.begin(), nums.end(), maxElement);
        int idx = distance(nums.begin(), it);

        return idx;
    }
};
