class Solution {
public:
    bool pal(string s){
        string t = s;
        reverse(s.begin(), s.end());
        return t == s;
    }

    // int countSubstrings(string s) {
    //     cout<<s.length();
    //     int ans = 0;
    //     int n = s.length();

    //     for(int i=0;i<n;i++){
    //         string temp = "";
    //         for(int j=i;j<n;j++){
    //             temp += s[j];
    //             if(pal(temp)){
    //                 ans++;
    //             }
    //         }
    //     }

    //     return ans;
    // }

    int ans = 0;

    void Helper(string s, string temp, int i){
        if (i >= s.length()) {
            if (pal(temp)) {
                ans++;
            }
            return;
        }

        Helper(s, temp, i+1);
        temp += s[i];
        Helper(s, temp, i+1);
    }

    int countSubstrings(string s){
        string temp;
        Helper(s, temp, 0);

        return ans;
    }
};
