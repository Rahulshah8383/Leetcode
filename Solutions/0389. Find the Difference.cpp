class Solution {
public:
    char findTheDifference(string s, string t) {
        // unordered_map<char, int> mp;
        // char c;
        // for(int i=0;i<s.length();i++){
        //     mp[s[i]]++;
        // }

        // for(int i=0;i<t.length();i++){
        //     if(mp[t[i]] == 0){
        //         c = t[i];
        //         break;
        //     }   
        // }

        s+=t; int c=0;
        
        for(auto x: s){
            c^=x;
        }
        return c;
    }
};
