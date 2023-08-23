class Solution {
public:
    bool dfs(int r, int c,vector<vector<char>>& board, string word, vector<vector<int>>&vis, int indx,int n, int m)
    {
        vis[r][c]=1;
        if(indx==word.length()) return true;
        for(int i= -1;i<=1;i++)
        {
            for(int j= -1;j<=1;j++)
            {
                if(abs(i)!=abs(j))
                {
                    int Newr=r+i;
                    int Newc=c+j;
                    
                    if(Newr>=0 && Newr<n && Newc>=0 && Newc<m && !vis[Newr][Newc] && board[Newr][Newc]==word[indx] )
                    {
                        if(dfs(Newr,Newc,board,word,vis,indx+1,n,m)==true) return true;
                    }
                }
            }
        }
         vis[r][c]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        char start=word[0];
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==start)
                {
                    if(dfs(i,j,board,word,vis,1,n,m)==true) return true;
                    
                }
            }
        }
       
        return false;
    }
};