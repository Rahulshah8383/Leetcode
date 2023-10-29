class Solution {
public:
    int Helper(vector<int>& nums, int n, int k){
        priority_queue<pair<int, int>> maxHeap;
        maxHeap.push({nums[0], 0});

        int ans = nums[0];

        for(int i=1;i<n;i++){
            while(i-maxHeap.top().second > k){
                maxHeap.pop();
            }

            int sum = max(0, maxHeap.top().first)+nums[i];
            ans = max(ans, sum);
            maxHeap.push({sum, i});
        }

        return ans;
    }

    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        return Helper(nums, n, k);
    }
};
