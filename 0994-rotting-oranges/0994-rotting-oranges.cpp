class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
       int tm=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(abs(i)!=abs(j))
                    {
                        int Newr=r+i;
                        int Newc=c+j;
                        if(Newr>=0 && Newr<n && Newc>=0 && Newc<m && grid[Newr][Newc]==1 && vis[Newr][Newc]!=2)
                        {
                            q.push({{Newr,Newc},t+1});
                            vis[Newr][Newc]=2;
                        }
                          tm=max(tm,t);
                    }
                    
                }
            }
        }
      
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]!=2)
                {
                    return -1;
                }
            }
        }
        return tm;
    }
};