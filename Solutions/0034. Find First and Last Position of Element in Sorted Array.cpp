class Solution {
public:
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

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int size = nums.size();
        int a = first(nums, 0, size-1, target, size);
        int b = last(nums, 0, size-1, target, size);
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};