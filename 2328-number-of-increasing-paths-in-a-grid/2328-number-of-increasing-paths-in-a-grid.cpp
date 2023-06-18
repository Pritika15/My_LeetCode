int M=1e9+7;
class Solution {
public:
    int dfs(int i, int j,vector<vector<int>>& grid,vector<vector<int>>&dp )
    {
        int m=grid.size();
        int n=grid[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
        long long ans=1;
        for(int k=-1;k<=1;k++)
        {
            for(int l=-1;l<=1;l++)
            {
                if(abs(k)!= abs(l))
                {
                    int Newi=i+k;
                    int Newj=j+l;
                    if(Newi>=0 && Newi<m && Newj>=0 && Newj<n && grid[Newi][Newj]>grid[i][j])
                    {
                        ans+=dfs(Newi,Newj,grid,dp);
                    }
                }
            }
        }
        return dp[i][j]=ans%M;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        long long count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                count+=dfs(i,j,grid,dp);
            }
        }
        return count%M;
        
    }
};