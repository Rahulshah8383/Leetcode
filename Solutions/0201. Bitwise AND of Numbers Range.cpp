class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // bitset<32> a(left);
        // bitset<32> b(right);
        // bitset<32> c(0);

        // for(int i=32;i>=0;i--){
        //     if((a[i] == b[i])){
        //        c[i] = a[i];
        //     }
        //     else{
        //         break;
        //     }
        // }

        // return c.to_ulong();

        int cnt = 0;
        while(left != right){
            left >>= 1;
            right >>= 1;
            cnt++;
        }

        return (left << cnt);
    }
};
