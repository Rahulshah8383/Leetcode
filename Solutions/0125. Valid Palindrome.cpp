class Solution {
public:
    bool isvalid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return true;
        }
        return false;
    }

    bool Pali(string temp){
        int i = 0;
        int j = temp.length() -1;

        while(i < j){
            if(temp[i] != temp[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }

    bool isPalindrome(string s) {
        string temp = "";

        for(int i=0;i<s.length();i++){
            if(isvalid(s[i])){
                temp.push_back(tolower(s[i]));
            }
        }

        return Pali(temp);
    }
};
