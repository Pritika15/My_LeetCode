class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m=pizza.size(); // no. of rows
        int n=pizza[0].size(); //no. of cols
        //now as we know that this approach would have overlapping sub problems hence we use dp
        vector<vector<vector<int>>>dp(vector(k,vector(m,vector(n,-1))));
        //As there are 3 changing parameters- m,n,k
        //calculating the preSum which is teh number of available apples corresponding to that particular cell
        vector<vector<int>>preSum(m+1,vector(n+1,0));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                preSum[i][j]=preSum[i+1][j]+preSum[i][j+1]-preSum[i+1][j+1]+(pizza[i][j]=='A');
            }
        }
      return  dfs(m,n,0,0,k-1,preSum,dp);
    }
    int dfs(int m, int n, int r, int c,int k, vector<vector<int>>&preSum,vector<vector<vector<int>>>&dp)
    {
        if(preSum[r][c]==0) return 0;
        if(k==0) return 1;
        if(dp[k][r][c]!= -1) return dp[k][r][c];
        int ans=0;
        for(int nr=r+1;nr<m;nr++)
        {
            if(preSum[r][c]-preSum[nr][c]>0)
            {
                ans=(ans+dfs(m,n,nr,c,k-1,preSum,dp))%1000000007;
            }
        }
        for(int nc=c+1;nc<n;nc++)
        {
            if(preSum[r][c]-preSum[r][nc]>0)
                ans=(ans+dfs(m,n,r,nc,k-1,preSum,dp))%1000000007;
        }
        
        return dp[k][r][c]=ans;
    }
};