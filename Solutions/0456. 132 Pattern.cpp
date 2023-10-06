class Solution {
public:
    /*
    void Helper(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& output) {
        if (i >= nums.size()) {
            if (output.size() > 2 && output.size() < 4) {
                ans.push_back(output);
            }
            return;
        }

        Helper(nums, i + 1, ans, output);
        int num = nums[i]; // Treat the element as an integer, not a character
        output.push_back(num);
        Helper(nums, i + 1, ans, output);
        output.pop_back(); // Remove the last element for backtracking
    }
    */

    bool find132pattern(vector<int>& nums) {
        /*
        vector<vector<int>> ans;
        vector<int> output;
        Helper(nums, 0, ans, output);

        for (int i=0;i<ans.size();i++) {
            int a = ans[i][0];
            int b = ans[i][1];
            int c = ans[i][2];

            if(a<c && b>c){
                return true;
            }
        }

        return false;
        */

    
        // int n = nums.size();
        // for(int i=0;i<n-2;i++){
        //     int a = nums[i];
        //     for(int j=i+1;j<n-1;j++){
        //         int b = nums[j];
        //         for(int k=j+1;k<n;k++){
        //             int c = nums[k];

        //             if(a<c && b>c){
        //                 cout<<a<<b<<c;
        //                 return true;
        //             }
        //         }
        //     }
        // }

        // return false;

        stack<int> s;
        int third = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < third) return true;
            while (!s.empty() && s.top() < nums[i]) {
                third = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
