class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];

        /*
        priority_queue<int> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        for(int i=1;i<k;i++){
            pq.pop();
        }

        return pq.top();
        */
    }
};
