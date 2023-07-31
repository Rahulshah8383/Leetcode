class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ump;
        int unique = INT_MAX;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }

        for(auto i : ump){
            if(i.second == 1){
                return i.first;
            }
        }
        return -1;
    }
};
