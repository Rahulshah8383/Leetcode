class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int n = nums.size();

        // bool contains1 = false;

        // for(int i=0;i<n;i++){
        //     if(nums[i] == 1){
        //         contains1 = true;
        //     }

        //     if(nums[i] <= 0 || nums[i] > n){
        //         nums[i] = 1;
        //     }
        // }

        // if(contains1 == false){
        //     return 1;
        // }

        // for(int i=0;i<n;i++){
        //     int num = abs(nums[i]);
        //     int idx = num - 1;

        //     if(nums[idx] < 0){
        //         continue;
        //     }
        //     nums[idx] *= -1;
        // }

        // for(int i=0;i<n;i++){
        //     if(nums[i] > 0){
        //         return i+1;
        //     }
        // }

        // return n+1;
        

        int n = nums.size();

        for(int i=0;i<n;i++){
            int x = nums[i];

            while(x>=1 && x<=n && x!=i+1 && nums[x-1] != x){
                swap(nums[x-1], nums[i]);
                x = nums[i];
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i] == i+1)
                continue;
            return i+1;
        }
        
        return n+1;
    }
};
