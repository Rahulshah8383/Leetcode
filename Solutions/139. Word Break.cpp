class Solution {
public:
    bool res(int i){
        if(i == 1){
            return true;
        }
        return false;
    }

    bool Helper(string s, unordered_set<string>& st,int idx, vector<int>& dp){
        if(idx >= s.size()){
            return true;
        }

        if(dp[idx] != -1){
            return res(dp[idx]);
        }
        
        string temp = "";
        for(int i=idx;i<s.size();i++){
            temp += s[i];
            if(st.find(temp) != st.end()){
                if(Helper(s, st, i+1, dp)){
                    dp[i] = 1;
                    return true;
                }
            }
        }
        dp[idx] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;

        for(string word : wordDict){
            st.insert(word);
        }

        vector<int> dp(s.size(), -1);

        return Helper(s, st, 0, dp);
    }
};
