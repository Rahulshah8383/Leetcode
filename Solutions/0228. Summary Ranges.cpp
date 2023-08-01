class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        for(int i=0;i<n;i++){
            string str = "";
            int j = i;

            while(j+1 < n && nums[j]+1 == nums[j+1]){
                j++;
            }

            if(j>i){    
                str += to_string(nums[i]);
                str = str + "->" + to_string(nums[j]);
            }
            else{
                str += to_string(nums[i]);
            }

            ans.push_back(str);
            i = j;
        }
        return ans;
    }
};
