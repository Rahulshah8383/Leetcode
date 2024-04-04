class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> count(101, 0);

        for(auto num : nums){
            count[num]++;
        }

        sort(count.rbegin(), count.rend());

        int max = count[0];
        int ans = 0;
        for(int i=0;i<count.size();i++){
            if(count[i] == max){
                ans += count[i];
            }
        }

        return ans;
    }
};
