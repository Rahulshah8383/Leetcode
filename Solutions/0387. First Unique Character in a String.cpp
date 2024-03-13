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

        // unordered_map<char, int> map;

        // for(int i=s.length()-1;i>=0;i--){
        //     map[s[i]]++;    
        // }

        // for(auto x: map){
        //     cout<<x.first<<" "<<x.second<<endl;
        //     size_t found = s.find(x.first);
        //     if((x.second == 1) && (found != string::npos))
        //         return found;
        // }

        // return -1;
    }
};
