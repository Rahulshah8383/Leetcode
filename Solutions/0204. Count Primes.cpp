class Solution {
public:
    int seive(int n){
        bool prime[n+1];
        memset(prime, true, sizeof(prime));

        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j += i){
                    prime[j] = false;
                }
            }
        }

        int count = 0;
        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;
            }
        }
        return count;   
    }
    int countPrimes(int n) {
        return seive(n);
    }
};
