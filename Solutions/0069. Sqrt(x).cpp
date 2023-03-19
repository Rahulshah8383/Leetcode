class Solution {
public:
    long long int BinarySearch(int n) {
        int s = 0;
        int e = n;
        int ans = -1;
        while(s<=e){
            long long  mid = s + (e-s)/2;

            long long sq = mid*mid;

            if(sq == n){
                return mid;
            }
            else if(sq < n){
                ans = mid;
                s = mid +1;   
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }

    int mySqrt(int x) {
        return BinarySearch(x);
    }
};
