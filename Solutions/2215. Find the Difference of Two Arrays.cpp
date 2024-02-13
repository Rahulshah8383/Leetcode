class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;

        vector<int> first;
        for(int i=0;i<nums1.size();i++){
            if((find(nums2.begin(), nums2.end(), nums1[i]) == nums2.end() && 
            find(first.begin(), first.end(), nums1[i]) == first.end())){
                first.push_back(nums1[i]);
            }
        }

        vector<int> second;
        for(int i=0;i<nums2.size();i++){
            if((find(nums1.begin(), nums1.end(), nums2[i]) == nums1.end()) &&
                find(second.begin(), second.end(), nums2[i]) == second.end()){
                second.push_back(nums2[i]);
            }
        }

        ans.push_back(first);
        ans.push_back(second);

        return ans;
    }
};
