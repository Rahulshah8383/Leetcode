class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto &num : nums)
            x^= num;

        int bit = 0;
        for(int i=0;i<32;i++){
            if(x & (1<<i)){
                bit = i;
                break;
            }
        }

        int first = 0;
        for(auto &num : nums){
            if(num & (1<<bit))
                first ^= num;
        }

        int second = first^x;
        return {first, second};
    }
};
