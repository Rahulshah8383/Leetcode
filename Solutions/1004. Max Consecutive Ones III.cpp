class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int no_zeros = 0;

        int i=0, j=0;

        while(j < nums.size()){
            if(nums[j] == 0){
                no_zeros++;
            }

            if(no_zeros <= k){ // Change here from '<' to '<='
                ans = max(ans, j-i+1);
                j++;
            }
            else{                
                while(no_zeros > k){
                    if(nums[i] == 0){
                        no_zeros--;
                    }
                    i++;
                }
                j++;
            }
        }

        return ans;
    }
};
