class Solution {
public:
    // int solve(string text1, string text2, int i, int j,vector<vector<int>>&dp)
    // {
    //     // base case
    //     if(i==0 || j==0)
    //     {
    //         return 0;
    //     }
    //     if(dp[i][j]!= -1) return dp[i][j];
    //     // Recursive function
    //     int match=-1e9;
    //     if(text1[i-1]==text2[j-1])
    //     {
    //         match=1+solve(text1,text2,i-1,j-1,dp);
    //     }
    //     int notMatch=max(solve(text1,text2,i-1,j,dp),solve(text1,text2,i,j-1,dp));
    //     return dp[i][j]=max(match,notMatch);
    // }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Corrected DP table dimensions
        // return solve(text1,text2,n,m,dp); // Corrected function call parameters
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
