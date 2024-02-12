class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int maxVowels(string s, int k) {
        int ans = 0;
        int no_vowel = 0;

        int i=0, j=0;

        while(j < s.length()){
            if(isVowel(s[j])){
                no_vowel++;
            }

            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                ans = max(ans, no_vowel);
                if(isVowel(s[i])){
                    no_vowel--;
                }
                i++; j++;
            }
        }

        return ans;
    }
};
