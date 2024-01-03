class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        string ans = "";

        for(int i=n-1; i>=0; i--){
            char c = num[i];
            int digit = c - '0';

            if((digit&1) != 0)
                return num.substr(0, i+1);
        }

        return "";
    }
};
