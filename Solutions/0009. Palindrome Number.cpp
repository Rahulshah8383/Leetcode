class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else{
            long long sum = 0;
            int y = x;
            while(y){
                sum = sum*10 + y%10;
                y/=10;
            }
            if(x == sum){
                return true;
            }
        }
        return false;
    }
};
