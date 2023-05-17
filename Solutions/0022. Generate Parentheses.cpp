class Solution {
public:
    void Helper(vector<string> &s, string str, int n, int m){
        if(n==0 && m==0){
            s.push_back(str);
            return;
        }

        if(m>0){
            Helper(s, str+")", n, m-1);
        }
        if(n>0){
            Helper(s, str+"(", n-1, m+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        Helper(res, "", n, 0);
        return res;
    }
};
