class Solution {
public:
    int helper(int r,int c,vector<vector<int>>&dp)
    {
        if(r==0 && c==0) return 1;
        if(r<0 || c<0) return 0;
        if(dp[r][c]!= -1) return dp[r][c];
        int up=helper(r-1,c,dp);
        int down=helper(r,c-1,dp);
        return dp[r][c]=up+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp);
    }
};