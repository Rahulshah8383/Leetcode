class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;

        for(int i=1;i<nums.size();i++){
            // bitset<32> bit(i);
            // if(bit.count() == k){
            //     // cout<<nums[i]<<" ";
            //     sum += nums[i];
            // }

            cout<<ceil(log2(i))<<" ";
        }  

        return sum; 
    }
};
