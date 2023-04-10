class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.length();i++){
            int k = i;
            int j;
            for(j=0;j<needle.length();j++){
                if(needle[j] == haystack[k]){
                    k++;
                }
                else{
                    break;
                }
            }
            if(j == needle.length())
                return i;
        }
        return -1;
    }
};
