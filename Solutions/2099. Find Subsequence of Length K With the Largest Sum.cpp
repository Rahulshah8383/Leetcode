class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        // while(!pq.empty()){
        //     cout<<pq.top().first<<":  "<<pq.top().second<<endl;
        //     pq.pop();

        // }

        vector<pair<int, int>> temp;
        for (int i = 0; i < k; i++) {
            temp.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }

        sort(temp.begin(), temp.end(), cmp);

        for (auto it : temp) {
            ans.push_back(nums[it.second]);
        }

        return ans;
    }
};
