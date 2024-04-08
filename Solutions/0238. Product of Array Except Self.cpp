class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        /*
        // 1. Brute Force

        for(int i=0;i<n;i++){
            int pro = 1;
            for(int j=0;j<n;j++){
                if(i == j){
                    continue;
                }
                pro *= nums[j];
            }

            ans.push_back(pro);
        }
        */

        // 2. using Division
        /*
        int pro = 1;
        int num_Zeros = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                num_Zeros++;
                continue;
            }
            pro *= nums[i];
        }

        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                if(num_Zeros > 0){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(pro/nums[i]);
                }
            }
            else{
                if(num_Zeros > 1){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(pro);
                }
            }
        }
        */


        // 3. withour Division
        /*
        vector<int> left(n), right(n);
        left[0] = 1;
        right[n-1] = 1;
        
        for(int i=1;i<n;i++){
            left[i] = left[i-1]*nums[i-1];
        }

        for(int i=n-2;i>=0;i--){
            right[i] = right[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            ans.push_back(left[i]*right[i]);
        }

        return ans
        */

        // 4. withour extra space
        vector<int> left(n);
        left[0] = 1;
              
        // Calculate products of all elements to the left of each index
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        
        int right_pro = 1; 

        // Calculate products of all elements to the right of each index
        for (int i = n - 1; i >= 0; i--) {
            left[i] *= right_pro;
            right_pro *= nums[i];
        } 

        return left;
    }
};
