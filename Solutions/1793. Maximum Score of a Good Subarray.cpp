class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        // int n = nums.size();
        // int score = 0;

        // for(int i=0;i<n;i++){
        //     priority_queue<int, vector<int>, greater<int>> pq;
        //     for(int j=i;j<n;j++){
        //         pq.push(nums[j]);
        //         int mini = pq.top(); 

        //         if(i <= k && k<= j)
        //             score = max(score, mini*(j-i+1));
        //     }
        // }

        // return score;

        int l = k, r = k;
        int min_val = nums[k];
        int max_score = min_val;

        while(l>0 || r<nums.size()-1){
            if(l==0 || (r<nums.size()-1 && nums[r+1] > nums[l-1]))
                r++;
            else
                l--;

            min_val = min(min_val, min(nums[l], nums[r]));
            max_score = max(max_score, min_val*(r-l+1));
        }

        return max_score;
    }
};
