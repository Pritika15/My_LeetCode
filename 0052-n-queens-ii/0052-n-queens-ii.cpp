class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board,int n)
    {
        int r=row;
        int c=col;
        while(r>=0 && c>=0)
        {
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        r=row;
        c=col;
        while(c>=0)
        {
             if(board[r][c]=='Q') return false;
            c--;
        }
        r=row;
        c=col;
        while(c>=0 && r<n)
        {
            if(board[r][c]=='Q') return false;
            r++;
            c--;
        }
        return true;
    }
    void Num(int col,vector<string>&board,int n,int &count)
    {
        
        if(col==n)
        {
            
            count++;
            return;
            
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(i,col,board,n))
            {
                board[i][col]='Q';
                Num(col+1,board,n,count);
                board[i][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
      
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        int count=0;
        Num(0,board,n,count);
        return count;
    }
};