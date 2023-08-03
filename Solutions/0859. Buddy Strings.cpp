class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = goal.length();
        if(s.length() != n){
            return false;
        }

        if(s == goal){
            set<char> st(s.begin(), s.end());
            return st.size() < n;
        }

        int i = 0, j = n-1;
        while(i<j && s[i] == goal[i]){
            i++;
        }

        while(j >=0 && s[j]==goal[j]){
            j--;
        }

        if(i<j){
            swap(s[i], s[j]);
        }

        return s == goal;
    }
};
