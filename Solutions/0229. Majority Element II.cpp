class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        int k = size/3;

        // wrong anwer : [2,2]
        // for(int i=0;i<size;i++){
        //     int count = 0;
        //     for(int j=i+1;j<size;j++){
        //         if(nums[i] == nums[j]){
        //             count++;
        //         }
        //     }

        //     if(count >= k){
        //         ans.push_back(nums[i]);
        //     }
        // }

        unordered_map<int, int> mp;

        for(int i=0;i<size;i++){
            mp[nums[i]]++;
        }

        for(auto it : mp){
            if(it.second > k){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
