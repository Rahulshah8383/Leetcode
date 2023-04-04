class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> ans;
        int count = 1;
        for(int i=0;i<s.length();i++){
            if(ans.find(s[i]) != ans.end()){
                count++;
                ans.clear();
            }
            ans.insert(s[i]);
        }
        return count;
    }
};
