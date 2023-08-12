#define ll long long

class Solution {
public:
    int Helper(vector<int>& coins, int N, int amount){
        vector<vector<ll>> dp(N,vector<ll>(amount+1,0));
        
        for(int i=1;i<=amount;i++){
            if(i%coins[0]==0)
            dp[0][i]=1;
        }
        
        for(int i=0;i<N;i++)
        dp[i][0]=1;
        
        for(int i=1;i<N;i++){
            for(int j=1;j<=amount;j++){
                ll a,b;
                a=b=0;
                
                a=dp[i-1][j];
                if(j>=coins[i])
                b=dp[i][j-coins[i]];
                
                dp[i][j]=(a+b);
            }
        }
        return dp[N-1][amount];
    }

    int change(int amount, vector<int>& coins) {
        return Helper(coins, coins.size(), amount);
    }
};
