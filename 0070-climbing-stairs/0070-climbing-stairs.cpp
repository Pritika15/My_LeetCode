class Solution {
public:
    int f(int n,vector<int>&dp)
    {
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    int climbStairs(int n) {
//         recursive code
//         Dp solution
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
    
//     O(2^N)
};