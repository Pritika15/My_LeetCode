class Solution {
public:
    bool isValid(int r, int c ,int n, int m,vector<vector<int>>& grid )
    {
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==0)
            return true;
        else
            return false;
    }
    void dfs(int r, int c, int n, int m ,vector<vector<int>>& grid)
    {
        grid[r][c]=1;
        int arr1[4]={1,-1,0,0};
        int arr2[4]={0,0,1,-1};
        for(int i=0;i<4;i++)
        {
            int nr=r+arr1[i];
            int nc=c+arr2[i];
            
            if(isValid(nr,nc,n,m,grid))
            {
                dfs(nr,nc,n,m,grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i*j==0 || i== n-1 || j== m-1)
                {
                    if(grid[i][j]==0)
                        dfs(i,j,n,m,grid);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    ans++;
                    dfs(i,j,n,m,grid);
                }
                    
            }
        }
        return ans;
    }
};