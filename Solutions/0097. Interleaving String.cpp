class Solution {
public:
    /*
    bool Helper(string s1, string s2, string s3, int l1, int l2, int l3){
        if(l1<0 && l2<0 && l3<0){
            return true;
        }

        if(l2>=0 && s3[l3] == s2[l2] && l1>=0 && s3[l3] == s1[l1]){
            return (Helper(s1, s2, s3, l1, l2-1, l3-1) || Helper(s1, s2, s3, l1-1, l2, l3-1));
        }

        else if(l1>=0 && s3[l3] == s1[l1]){
            return Helper(s1, s2, s3, l1-1, l2, l3-1);
        }

        else if(l2>=0 && s3[l3] == s2[l2]){
            return Helper(s1, s2, s3, l1, l2-1, l3-1);
        }

        else{
            return false;
        }
    }
    */

    bool Helper(string &s1, string &s2, string &s3, int l1, int l2, int l3, vector<vector<int>> &dp){
        if(l1<0 && l2<0 && l3<0){
            return true;
        }

        if(l1>=0 && l2>=0 && dp[l1][l2] != -1){
            return dp[l1][l2];
        }

        if(l2>=0 && s3[l3] == s2[l2] && l1>=0 && s3[l3] == s1[l1]){
            return dp[l1][l2] =(Helper(s1, s2, s3, l1, l2-1, l3-1, dp) || Helper(s1, s2, s3, l1-1, l2, l3-1, dp));
        }

        else if(l1>=0 && s3[l3] == s1[l1]){
            return Helper(s1, s2, s3, l1-1, l2, l3-1, dp);
        }

        else if(l2>=0 && s3[l3] == s2[l2]){
            return Helper(s1, s2, s3, l1, l2-1, l3-1, dp);
        }

        else{
            return false;
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();

        if(l3 != l1 + l2){
            return false;
        }

        // return Helper(s1, s2, s3, l1-1, l2-1, l3-1);

        vector<vector<int>> dp(l1+1, vector<int>(l2+1, -1));
        return Helper(s1, s2, s3, l1-1, l2-1, l3-1, dp);
    }
};
