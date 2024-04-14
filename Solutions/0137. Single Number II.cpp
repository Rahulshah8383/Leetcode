class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*    using hash map : (n*log(m)) + O(m), O(m)

        int ans = 0;
        // O(m) : m = (n/2 + 1)
        unordered_map<int, int> mp;

        // (n*log(m))
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        // O(m)
        for(auto it : mp){
            if(it.second == 1){
                ans =  it.first;
                break;
            }
        }

        return ans;
    */

        /*

        // bit masking 
        int ans = 0;
        for(int bitIndex = 0; bitIndex <= 31 ; bitIndex++) {
            int cnt = 0;
            for(int i = 0;i<nums.size();i++) {
                if( ( nums[i] & (1 << bitIndex)) ){         // Ith bit is set or not
                    cnt++;        //counting the set bit            //n&(mask)==1  // // mask=(1<<bitIndex)
                }                       
            }
            if(cnt % 3 == 1) {                  // set the Ith bit  mask = (1<<i);
                ans = (ans | (1 << bitIndex));                  //n =  n | (mask)
            }
        }
        return ans;
        */
    

        /*
        // N logN + N/3
        // O(1)

        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=1;i<n;i = i+ 3){
            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
        }
        
        return nums[n-1];
        */
    }
};
