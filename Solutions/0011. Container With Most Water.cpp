class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size()-1;
        int left = 0;
        int water = 0;

        while(left < right){
            if(height[left] < height[right]){
                water = max(water, (right-left)*height[left]);
                left++;
            }
            else{
                water = max(water, (right-left)*height[right]);
                right--;
            }
        }

        return water;
    }
};
