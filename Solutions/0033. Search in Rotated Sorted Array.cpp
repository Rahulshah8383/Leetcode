class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int li = 0, hi=n-1;

        while(li < hi){
            int mid = (li + hi)/2;
            if(nums[mid] > nums[hi])
                li = mid+1;
            else
                hi = mid;
        }

        int rot = li;
        li = 0, hi=n-1;

        while(li <= hi){
            int mid = (li + hi)/2;
            int rmid = (mid+rot)%n;

            if(nums[rmid] == target){
                return rmid;
            }
            else if(nums[rmid] > target){
                hi = mid - 1;
            }
            else{
                li = mid+1;
            }
        }
        return -1;
        
        /*
        int n = nums.size();
        for(int i=0;i<n;i++)
            if(nums[i] == target)
                return i;
        return -1;
        */
    }
};
