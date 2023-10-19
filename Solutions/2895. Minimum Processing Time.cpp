class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int maxi = INT_MIN;
        sort(tasks.begin(),tasks.end());
        int count = 0;
        sort(processorTime.rbegin(),processorTime.rend());
        for(int i=0;i<processorTime.size();i++){
            int x  = processorTime[i] + max({tasks[4*count],tasks[4*count+1],tasks[4*count+2],tasks[4*count+3]});
            // cout<<x;
            maxi = max(maxi,x);
            count++;
        }
        return maxi;
    }
};
