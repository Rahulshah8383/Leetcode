class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums2.size();
        vector<int> Next_Greater_Right(n, -1);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums2[j] > nums2[i]){
                    Next_Greater_Right[i]  = nums2[j];
                    break;
                }
            }
        }

        for(auto x : nums1){
            auto it = find(nums2.begin(), nums2.end(), x);
            int index = std::distance(nums2.begin(), it);
            ans.push_back(Next_Greater_Right[index]);
        }

        return ans;
    }
};
