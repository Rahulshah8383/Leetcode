class Solution {
public:
    bool static cmp(char a, char b){
        return static_cast<int>(a) < static_cast<int>(b);
    }

    string sortVowels(string s) {
        string vowel = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                vowel += s[i];
            }
        }

        sort(vowel.begin(), vowel.end(), cmp);
        int j = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                s[i] = vowel[j++];
            }
        }

        return s;
    }
};
