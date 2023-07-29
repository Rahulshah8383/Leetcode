class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // O(N^3)
        // int maxi = INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i;j<nums.size();j++){
        //         int sum = 0;
        //         for(int k=i;k<=j;k++){
        //             sum += nums[k];
        //         }
        //         maxi = max(maxi, sum);
        //     }
        // }

        // O(N^2)
        // int maxi = INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     int sum = 0;
        //     for(int j=i;j<nums.size();j++){
        //         sum += nums[j];
        //         maxi = max(maxi, sum);
        //     }
        // }

        // Kadanes's alg --> O(N)
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            maxi = max(maxi, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        
        return maxi;
    }
};
