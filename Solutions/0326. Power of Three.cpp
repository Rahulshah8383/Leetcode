class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1){
            return false;
        }

        if(n == 1){
            return true;
        }

        double ans = 1;
        for(int i=0;i<n;i++){
            ans = ans*3;
            if(ans == n){
                return true;
            }

            else if(ans > n){
                break;
            }
        }

        return false;
    }
};
