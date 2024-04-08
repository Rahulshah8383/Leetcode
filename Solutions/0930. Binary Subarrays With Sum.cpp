class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // 1. Two for loop

        // int n = nums.size();
        // int count = 0;

        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum += nums[j];
        //         if(sum == goal){
        //             count++;
        //         }

        //         else if(sum > goal){
        //             break;
        //         }
        //     }
        // }

        // return count;

        // 2. map
        /*
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            sum += nums[i];
            int x = sum - goal;

            if(mp.find(x) != mp.end()){
                count += mp[x];
            }

            mp[sum]++;
        }
        return count;
        */

        // 3. sliding window
        int i = 0, j = 0;
        int n = nums.size();
        int wind_sum = 0;
        int ans = 0, count_zeros = 0;

        while(j<n){
            wind_sum += nums[j];

            while(i<j && (nums[i] == 0 || wind_sum > goal)){
                if(nums[i] == 0){
                    count_zeros++;
                }
                else{
                    count_zeros = 0;
                }

                wind_sum -= nums[i];
                i++;

            }

            if(wind_sum == goal){
                ans += 1 + count_zeros;
            }
            j++;
        }

        return ans;
    }
};
