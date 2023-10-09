class Solution {
public:
    /*
    int first(vector<int>& arr, int low, int high, int x, int n){
        if (high >= low) {
            int mid = low + (high - low) / 2;
            if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
                return mid;
            else if (x > arr[mid])
                return first(arr, (mid + 1), high, x, n);
            else
                return first(arr, low, (mid - 1), x, n);
        }
        return -1;
    }

    int last(vector<int>& arr, int low, int high, int x, int n){
        if (high >= low) {
            int mid = low + (high - low) / 2;
            if ((mid == n - 1 || x < arr[mid + 1])
                && arr[mid] == x)
                return mid;
            else if (x < arr[mid])
                return last(arr, low, (mid - 1), x, n);
            else
                return last(arr, (mid + 1), high, x, n);
        }
        return -1;
    }
    */

    nt binarySearch(vector<int>& nums, int target, bool findright){
        int low = 0;
        int high = nums.size()-1;
        int index = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                index = mid;
                if(findright){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }

            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // vector<int> res;
        // int size = nums.size();
        // int a = first(nums, 0, size-1, target, size);
        // int b = last(nums, 0, size-1, target, size);
        // res.push_back(a);
        // res.push_back(b);
        // return res;

        /*
        // O(N), O(N)
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        
        vector<int> res;
        
        if(ans.size() == 0){
            res.push_back(-1);
            res.push_back(-1);
        }
        else if(ans.size() == 1){
            res.push_back(ans[0]);
            res.push_back(ans[0]);
        }
        else{
            res.push_back(ans[0]);
            res.push_back(ans[ans.size()-1]);
        }
        
        return res;
        */

        int left = binarySearch(nums, target, false);
       int right = binarySearch(nums, target, true);
       
        if(left <= right){
            return {left, right};
        }
        else{
           return {-1, -1};
        }
    }
};
