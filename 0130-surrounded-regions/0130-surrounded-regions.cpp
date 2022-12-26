class Solution {
public:
    void dfs(int i, int j,vector<vector<char>>& board,vector<vector<char>>&vis)
    {
        vis[i][j]=1;
        int r=board.size();
        int c=board[0].size();
        for(int k=-1;k<=1;k++)
        {
            for(int l=-1;l<=1;l++)
            {
                if(abs(k)!= abs(l))
                {
                    int Newi=i+k;
                    int Newj=j+l;
                    if(Newi>=0 && Newi<r && Newj>=0 && Newj<c && !vis[Newi][Newj] && board[Newi][Newj]=='O')
                    {
                        dfs(Newi,Newj,board,vis);
                    }
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<char>>vis(r,vector<char>(c,0));
        for(int j=0;j<c;j++) //first row
        {
            if(!vis[0][j] && board[0][j]=='O')
            {
                dfs(0,j,board,vis);
            }
        }
         for(int i=0;i<r;i++) //first col
        {
            if(!vis[i][0] && board[i][0]=='O')
            {
                dfs(i,0,board,vis);
            }
        }
        for(int j=0;j<c;j++) //last row
        {
            if(!vis[r-1][j] && board[r-1][j]=='O')
            {
                dfs(r-1,j,board,vis);
            }
        }
        for(int i=0;i<r;i++) //last col
        {
            if(!vis[i][c-1] && board[i][c-1]=='O')
            {
                dfs(i,c-1,board,vis);
            }
        }
        for(int p=0;p<r;p++)
        {
            for(int q=0;q<c;q++)
            {
                if(vis[p][q]==0)
                {
                    board[p][q]='X';
                }
            }
        }
        
    }
};