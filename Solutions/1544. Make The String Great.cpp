class Solution {
public:
    string makeGood(string s) {
       int n = s.size();

       if(n <= 1){
        return s;
       }

       stack<char> st; 

       for(char c : s){
        if(!st.empty() && std::abs(c - st.top()) == 32){
            st.pop();
        }
        else{
            st.push(c);
        }
       }

        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
