class Solution {
public:
    int atmost(int k,vector<int>& nums){
         unordered_map<int,int> mp;
         int count=0,j=0;
         
         for(int i=0;i<nums.size();i++){
             mp[nums[i]]++;
             while(mp.size()>k){
                 if(mp[nums[j]]==1)mp.erase(nums[j]);
                 else mp[nums[j]]--;

                j++;
            }
            count+= i-j+1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(k,nums)-atmost(k-1,nums);
    }
};
