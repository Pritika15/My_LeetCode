class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,0));
         vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int d=q.front().second;
            dist[row][col]=d;
            q.pop();
            
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(abs(i)!=abs(j))
                    {
                        int NewR=row+i;
                        int NewC=col+j;
                        
                        if(NewR>=0 && NewR<n && NewC>=0 && NewC<m && !vis[NewR][NewC])
                        {
                            vis[NewR][NewC]=1;
                            q.push({{NewR,NewC},d+1});
                        }
                    }
                }
            }
            
        }
        return dist;
    }
};