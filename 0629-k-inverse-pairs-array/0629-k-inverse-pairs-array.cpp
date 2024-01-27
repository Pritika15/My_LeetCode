class Solution {
public:
    int mod=1e9+7;
    int dp[1001][1001];
    int solve(int n, int k)
    {
//         base case
        if(k<0) return 0;
        if(k==0) return 1;
        if(dp[n][k]!= -1) return dp[n][k];
//         recurrence relation
        int ans=0;
        for(int i=0;i<n;i++)
        {ans+=solve(n-1,k-i);
        ans=ans%mod;
        }
        return dp[n][k]=ans;
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};
