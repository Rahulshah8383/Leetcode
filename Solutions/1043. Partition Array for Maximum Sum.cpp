class Solution {
public:
    int recursion(int idx, vector<int>& arr, int k, int n, vector<int>& dp){
        if(idx >= n){
            return 0;
        }

        if(dp[idx]!=-1)
            return dp[idx];

        int len = 0;
        int maxi = 0;
        int maxAns = 0;
        for(int i=idx;i<min(idx+k, n);i++){
            len++;
            maxi = max(maxi, arr[i]);
            int sum = maxi*len + recursion(i+1, arr, k, n, dp);
            maxAns = max(maxAns, sum);
        }

        return dp[idx] =  maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return recursion(0, arr, k, n, dp);
    }
};
