class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool flag = false;
        for (int i = s.length() - 1; i >= 0; i--) {
            // Once the first character from last is encountered, set char_flag to true.
            if ((s[i] >= 'a' && s[i] <= 'z')
                || (s[i] >= 'A' && s[i] <= 'Z')) {
                flag = true;
                count++;
            }
            
// When the first space after the characters (from the last) is  encountered, return the length of the last word
            else {
                if (flag == true)
                    return count;
            }
        }
        return count;
    }
};
