class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        int size = s.length();
        for(int i=0;i<s.length();i++){
            if(s[i] == '1'){
                s[i] = '0';
                count++;
            }
        }

        // make odd binary number
        s[size-1] = '1';

        if(count == 1){    
            return s;
        }

        // -1 from count because, we use 1, more bitmaking string to odd
        for(int i=0;i<count-1;i++){
            s[i] = '1';
        }

        return s;
    }
};
