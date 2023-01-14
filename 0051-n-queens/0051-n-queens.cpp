class Solution {
public:
    bool isSafe(int col, int row, vector<string>board,int n)
    {
        int c=col;
        int r=row;
        
        while(c>=0 && r>=0)
        {
            if(board[r][c]=='Q') return false;
            c--;
            r--;
        }
        c=col;
        r=row;
        while(c>=0)
        {
            if(board[r][c]=='Q') return false;
            c--;
        }
        c=col;
        r=row;
        while(c>=0 && r<n)
        {
            if(board[r][c]=='Q') return false;
            c--;
            r++;
        }
        return true;
    }
    void place(int col, vector<vector<string>> &ans,vector<string>&board,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(col,i,board,n))
            {
                board[i][col]='Q';
                place(col+1,ans,board,n);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        place(0,ans,board,n);
        return ans;
    }
};