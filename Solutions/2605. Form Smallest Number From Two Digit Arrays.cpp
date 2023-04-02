class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();  
        vector<int> ans;
        
        for(int i=0;i<size1;i++){
            for(int j=0;j<size2;j++){
                if(nums1[i] == nums2[j]){
                    ans.push_back(nums1[i]);
                }
                else{
                    int sum1 = nums1[i] * pow(10, floor(log10(nums2[j])) + 1) + nums2[j];
                    int sum2 = nums2[j] * pow(10, floor(log10(nums1[i])) + 1) + nums1[i];
                    ans.push_back(sum1);
                    ans.push_back(sum2);
                }
                
            }
        }

        int min = INT_MAX;
        for(auto i: ans){
            if(min > i){
                min = i;
            }
        }
        return min;
    }
};
