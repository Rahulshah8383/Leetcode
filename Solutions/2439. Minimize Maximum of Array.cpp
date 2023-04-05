class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum = 0, answer = 0;
        
        for(int i=0;i<nums.size();++i) {
            sum += nums[i];
            answer = max(answer, (sum + i) / (i + 1));
        }
        
        return answer;
    }
};
