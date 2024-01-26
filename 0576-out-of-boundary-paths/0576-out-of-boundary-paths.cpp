class Solution {
public:
    int dp[55][55][55];
   
    long long mod=1e9+7;
    int solve(int m, int n, int maxMove, int i, int j)
    {
        if(i<0 || i>=m || j<0 || j>=n)
        {
            return 1;
        }
        if(maxMove<=0) return 0;
        if(dp[i][j][maxMove]!= -1) return dp[i][j][maxMove];
       int up=solve(m,n,maxMove-1,i-1,j);
        int down=solve(m,n,maxMove-1,i+1,j);
        int left=solve(m,n,maxMove-1,i,j-1);
        int right=solve(m,n,maxMove-1,i,j+1);
        
        return dp[i][j][maxMove] = (up % mod + down % mod + left % mod + right % mod) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow,startColumn);
    }
};