class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        vector<string> v;
        int n = s.size();
        int i = 0;

        while(i < n){
            if(s[i] == ' '){
                i++;
                continue;
            }
            else{
                string temp = "";
                while(s[i] != ' ' && i < n){
                    temp += s[i];
                    i++;
                }
                // cout<<temp<<endl;
                v.push_back(temp);
            }
        }

        for(int i=v.size()-1;i>=0;i--){
            ans += v[i];
            if(i != 0){
                ans += ' ';
            }
        }

        return ans;
    }
};
