class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
        int ans = INT_MIN;
        for(int i=0;i<nums.size()-1;i++) {
            for(int j=i+1;j<nums.size();j++) {
                int prod = 1;
                for(int k=i;k<=j;k++) 
                    prod *= nums[k];
                ans = max(ans, prod);    
            }
        }
        return ans;
        */

        /*
        int ans = nums[0];
        for(int i=0;i<nums.size()-1;i++) {
            int prod = nums[i];
            for(int j=i+1;j<nums.size();j++) {
                ans = max(ans, prod);   
                prod *= nums[j];
            }
            ans = max(ans, prod); //manages (n-1)th term 
        }
        return ans;
        */

        int maxLeft = nums[0];
        int maxRight = nums[0];
        
        int prod = 1;
        bool zeroPresent =  false;
        
        for(auto i:nums) {
            prod *= i;
            if(i == 0) {
                zeroPresent = true;
                prod = 1;
                continue;
            }
            maxLeft = max(maxLeft,prod);
        }
        
        prod = 1;
        for(int j=nums.size()-1;j>=0;j--) {
            prod *= nums[j];
            if(nums[j] == 0) {
                zeroPresent = true;
                prod = 1;
                continue;
            }
            maxRight = max(maxRight,prod);
        }
        
        if(zeroPresent) 
            return max(max(maxLeft,maxRight),0);
        return max(maxLeft,maxRight);
    }
};
