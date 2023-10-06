class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        // O(N^2), O(1)
        /*
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
        }
        */

        // O(N), O(N)
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]){
                count += mp[nums[i]];
            }
            mp[nums[i]]++;
        }

        return count;
    }
};
