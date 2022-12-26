class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>&vis)
    {
        vis[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(abs(i)!=abs(j))
                {
                    int Newr=r+i;
                    int Newc=c+j;
                    
                    if(Newr>=0 && Newr<n && Newc>=0 && Newc<m && !vis[Newr][Newc] && grid[Newr][Newc]==1)
                    {
                        dfs(Newr,Newc,grid,vis);
                    }
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++)//first row
        {
            if(!vis[0][j] && grid[0][j]==1)
            {
                dfs(0,j,grid,vis);
            }
        }
        for(int i=0;i<n;i++)//first col
        {
            if(!vis[i][0] && grid[i][0]==1)
            {
                dfs(i,0,grid,vis);
            }
        }
        for(int j=0;j<m;j++)//last row
        {
            if(!vis[n-1][j] && grid[n-1][j]==1)
            {
                dfs(n-1,j,grid,vis);
            }
        }
          for(int i=0;i<n;i++)//lastt col
        {
            if(!vis[i][m-1] && grid[i][m-1]==1)
            {
                dfs(i,m-1,grid,vis);
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};