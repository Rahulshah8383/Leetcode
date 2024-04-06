class Solution {
public:
    // o(NXM), O(N)
    string customSortString(string order, string s) {
        // space : O(M) : M size of s
        string ans = "";

        // O(N^2)
        for(int i=0;i<order.length();i++){ // size of order : N
            char ch = order[i];
            for(int j=0;j<s.length();j++){ // size of s : M
                if(s[j] == ch){
                    ans += ch;
                    s[j] = '0';
                }
            }
        }

        // O(N)
        for(auto it : s){
            if(it != '0'){
                ans.push_back(it);
            }
        }

        return ans;
    }
};
