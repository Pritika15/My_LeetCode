class Solution {
public:
    //vector<int>DirecR={-1,0,1,0,-1,0,1,0};
   // vector<int>DirecC={0,1,0,-1};
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<char>>&vis)
    {
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int x=grid.size();
        int y=grid[0].size();
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
          for(int k=-1 ;k<=1;k++)
          {
              for(int l=-1;l<=1;l++)
              {
                  if(abs(k)!=abs(l))
                  {
                      int newR=r+k;
                      int newC=c+l;
                      
                      if(newR>=0 && newR<x && newC>=0 && newC<y && grid[newR][newC]=='1' && !vis[newR][newC])
                      {
                          q.push({newR,newC});
                          vis[newR][newC]=1;
                      }
                  }
              }
          }
            
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<char>>vis(r,vector<char>(c,0));
        int count=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};