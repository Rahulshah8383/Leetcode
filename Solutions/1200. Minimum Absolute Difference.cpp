class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();

        int min = INT_MAX;
        for(int i=1;i<n;i++){
            int diff = arr[i] - arr[i-1];
            if(diff < min){
                min = diff;
            }
        }

        for(int i=1;i<n;i++){
            int diff = arr[i] - arr[i-1];
            
            if(diff == min){
                vector<int> v;
                v.push_back(arr[i-1]);
                v.push_back(arr[i]);
                ans.push_back(v);
            }
        }        

        return ans;
    }
};
