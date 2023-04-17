class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        sort(divisors.begin(), divisors.end());
        int ans = divisors[0];
        int count = 0;
        for(int i=0;i<divisors.size();i++){
            int a = divisors[i];
            int temp_count = 0;
            
            for(int j=0;j<nums.size();j++){
                int b = nums[j];
                if(b%a == 0){
                    temp_count++;
                }
            }
            if(temp_count > count){
                count = temp_count;
                ans = divisors[i];
            }
        }
        
        return ans;
    }
};
