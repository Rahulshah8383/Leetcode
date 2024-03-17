class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // o(nlogn)
        // int ans;

        // sort(nums.begin(), nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(i ==  nums[i]){
        //         continue;
        //     }
        //     else{
        //         return i;
        //     }
        // }

        // return nums.size();   

        // O(n)
        // int total = nums.size()*(nums.size()+1)/2;
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        // return total-sum;

        int ans = nums.size();
        int i=0;

        for(int num : nums){
            ans ^= num;
            ans ^= i;
            i++;
        }

        return ans;
    }
};
