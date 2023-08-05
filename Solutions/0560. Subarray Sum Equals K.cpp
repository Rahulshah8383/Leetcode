class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j=i;j<nums.size();j++){
                sum += nums[j];
                if(k == sum){
                    count++;
                }
            }
        }

        return count;
        */

        unordered_map<int, int> map;
        int sum = 0, count = 0;

        map[sum] = 1;

        for(auto i : nums){
            sum += i;
            int prefix = sum - k;
            if(map.find(prefix) != map.end()){
                count += map[prefix];
            }
            map[sum]++;
        }
        return count;
    }
};
