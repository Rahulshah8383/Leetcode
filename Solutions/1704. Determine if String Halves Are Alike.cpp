class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    bool halvesAreAlike(string s) {
        int len = s.size();
        string a = s.substr(0, len/2);
        string b = s.substr(len/2, len);
        int l1 = 0, l2 = 0;

        for(int i=0;i<len/2;i++){
            if(isVowel(a[i]))
                l1++;

            if(isVowel(b[i]))
                l2++;
        }

        return l1 == l2;
    }
};
