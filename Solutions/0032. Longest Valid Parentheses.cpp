class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int count = 0;
        for(int i=0; i< s.length(); ++i){
            if(s[i] == '('){
                stk.push(i);
            }
            else{
                stk.pop();
                if(stk.empty())
                    stk.push(i);
                count = max(count, i - stk.top());
                
            }
        }
        return count;
    }
};
