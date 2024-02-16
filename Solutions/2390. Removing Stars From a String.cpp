class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        
        for(int i=0;i<s.size();i++){
            if(s[i] != '*'){
                ans += s[i];
            }
            else{
                ans.pop_back();
            }
        }

        return ans;

        // stack<char> st;

        // for(int i=0;i<s.length();i++){
        //     if(s[i] != '*'){
        //         st.push(s[i]);
        //     }
        //     else{
        //         st.pop();
        //     }
        // }

        // string ans = ""; 
        // while(!st.empty()){
        //     ans += st.top();
        //     st.pop();
        // }

        // reverse(ans.begin(), ans.end());
        // return ans;
    }
};
