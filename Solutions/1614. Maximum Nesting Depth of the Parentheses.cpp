class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        stack<char> st;

        for(char c : s){
            if(c == '('){
                st.push(c);
            }
            else if(c == ')'){
                st.pop();
            }

            result = max(result, int(st.size()));
        }

        return result;
    }
};
