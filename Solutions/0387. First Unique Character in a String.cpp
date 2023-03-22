class Solution {
public:
    int firstUniqChar(string s) {
        int fi[256];

        for(int i=0;i<256;i++){
            fi[i] = -1;
        }

        for(int i=0;i<s.length();i++){
            if(fi[s[i]]==-1){
                fi[s[i]] = i;
            }
            else{
                fi[s[i]] = -2;
            }
        }

        int ans = INT_MAX;

        for(int i=0;i<256;i++){
            if(fi[i]>=0){
                ans = min(ans, fi[i]);
            }
        }

        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};
