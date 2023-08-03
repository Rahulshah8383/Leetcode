class Solution {
public:
    double solve(int n,int k, int row,int col,vector<vector<vector<double>>>&dp){
        if(row<0||col<0||row>=n||col>=n){
            return 0;
        }
        if(k==0){
            return 1;
        }
        if(dp[row][col][k]!=-1){
            return dp[row][col][k];
        }
        vector<pair<int,int>>dir={{-2,-1},{-2,1},{2,-1},{2,1},{1,2},{-1,2},{1,-2},{-1,-2}};
        double ans=0;
        for(auto ele:dir){
            int nr=row+ele.first,nc=col+ele.second;
            ans+=solve(n,k-1,nr,nc,dp);
        }
        return dp[row][col][k]=ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        double total_outcomes=pow(8,k);
        double fav_outcomes=solve(n,k,row,column,dp);
        double probability=fav_outcomes/total_outcomes;
        return probability;
    }
};
