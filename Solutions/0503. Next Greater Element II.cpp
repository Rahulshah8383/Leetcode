class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, -1);

        stack<int> st;
        for(int i=0;i<2*n;i++){
            while(st.empty() == 0 && nums[i%n] > nums[st.top()]){
                //goes through twice as circular
                arr[st.top()] = nums[i%n];
                st.pop();
            }

            if(i < n){
                st.push(i);
            }
        }

        return arr;
    }
}; 
