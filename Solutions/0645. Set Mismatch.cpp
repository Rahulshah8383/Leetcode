class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, -1);

        // sort(nums.begin(), nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] != i+1){
        //         ans.push_back(nums[i]);
        //         ans.push_back(i+1);
        //         break;
        //     }
        // }

        unordered_map<int, int> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        // for(int i=1;i<=nums.size();i++){
        //     cout<<i<<" "<<mp[i]<<endl;
        // }

        for(int i=1;i<=nums.size();i++){
            if(mp[i] == 0){
                ans[1] = i; 
            }

            if(mp[i] == 2){
                ans[0] = i;
            }
        }

        return ans;
    }
};
