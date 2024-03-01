class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // int n = temp.size();
        // vector<int> ans;

        // for(int i=0;i<n;i++){
        //     bool isfind = true;
        //     for(int j=i+1;j<n;j++){
        //         if(temp[j] > temp[i]){
        //             isfind = false;
        //             ans.push_back(j-i);
        //             break;
        //         }
        //     }

        //     if(isfind){
        //         ans.push_back(0);
        //     }
        // }
        // return ans;

        int len = temp.size();
        stack<int> s;
        s.push(len - 1);
        vector<int> res(len);
        // looping from right to left, starting from the penultimate element
        for (int i = len - 2, n; i >=0; --i) {
            n = temp[i];
            // removing all the indexes stacked before if they are smaller
            while (s.size() && n >= temp[s.top()]) s.pop();
            // if we still have something in the stack, we update res
            if (s.size()) res[i] = s.top() - i;
            // updating the stack
            s.push(i);
        }
        return res;
    }
};
