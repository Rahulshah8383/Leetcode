class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> seen;
        int size = nums.size();

        for(int i=0;i<size;i++){
            if(seen.count(nums[i])>0){
                seen[nums[i]]++;
            }
            else{
                seen[nums[i]] = 1;
            }
        }   

        int ans;
        for(auto i: seen){
            if(i.second > size/2){
                ans = i.first;
            }
        }

        return ans;
    }
};
