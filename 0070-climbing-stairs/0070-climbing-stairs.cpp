class Solution {
public:
    // int f(int n,vector<int>&dp)
    // {
//     Dp solution:Memoization: top-down appraoch 
    //     if(n==0 || n==1) return 1;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=f(n-1,dp)+f(n-2,dp);
    // }
    int climbStairs(int n) {
//         recursive code
//         
//         Tabulation:Bottom up approach 
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
        // return f(n,dp);
    }
    
//     O(2^N)
};