class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;

        for(int i=0;i<s.size();i++){
            vector<bool> visited(256);
            for(int j = i;j<s.size();j++){
                if(visited[s[j]] == true){
                    break;
                }
                else{
                    count = max(count, j-i+1);
                    visited[s[j]] = true;
                }
            }
            visited[s[i]] = false;
        }
        return count;
    }
};
