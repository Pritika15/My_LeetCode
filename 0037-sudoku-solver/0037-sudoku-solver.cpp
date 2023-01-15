class Solution {
public:
    bool isSafe(int r, int c,char ch,vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[r][i]==ch) return false;
            if(board[i][c]==ch) return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==ch) return false;
            
            
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int row=0;row<board.size();row++)
        {
            for(int col=0;col<board[0].size();col++)
            {
                if(board[row][col]=='.')
                {
                    for(char ch='1';ch<='9';ch++)
                    {
                        if(isSafe(row,col,ch,board))
                        {
                            board[row][col]=ch;
                            
                            if(solve(board)==true)
                                return true;
                            else
                                board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};