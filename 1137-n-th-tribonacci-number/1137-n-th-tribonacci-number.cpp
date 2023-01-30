class Solution {
public:
    int helper(int n,vector<int>&dp)
    {
         if(dp[n]!= -1) return dp[n];
        if(n==0) return 0;
        if(n==1||n==2) return 1;
       
        
        return dp[n]=helper(n-1,dp)+helper(n-2,dp)+helper(n-3,dp);
    }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};