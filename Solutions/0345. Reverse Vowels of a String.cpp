class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string reverseVowels(string s) {
        string ans = "";

        int start = 0;
        int end = s.size()-1;

        while(start < end){
            if(isVowel(s[start]) && isVowel(s[end])){
                swap(s[start], s[end]);
                start++; end--;
            }

            else if(isVowel(s[start])){
                end--;
            }
            else{
                start++;
            }
        }

        return s;
    }
};
