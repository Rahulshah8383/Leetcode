class Solution {
public:
    int fib(int n) {
        // Approach 1
        // if(n==0){
        //     return 0;
        // }

        // if(n==1){
        //     return n=1;
        // }

        // int ans = fib(n-1) + fib(n-2);

        // return ans;

        // Approach 2
        if (n < 2) {
            return n;
        }
        
        int one = 1;
        int two = 0;
        for (int i = 2; i < n; ++i) {
            int curr = one + two;
            two = one;
            one = curr;
        }

        return one + two;
    }
};
