class Solution {
public:
   pair<int,int> findPos( int n, int curr)
   {
       int r=n-(curr-1)/n-1;
       int c=(curr-1)%n;
       if(r%2==n%2)
       {
           return {r,c=n-1-c};  
       }
    return {r,c};
       
           
      
   }
    int snakesAndLadders(vector<vector<int>>& board) {
        int steps=0;
        int row=board.size();
        vector<vector<int>>vis(row,vector<int>(row,-1));
        queue<int>q;
        q.push(1);
        vis[row-1][0]=1;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int x=q.front();
               
                if(x==row*row) return steps;
                 q.pop();
                for(int k=1;k<=6;k++)
                {
                    if(k+x>row*row) break;
                   
                 pair<int,int>p= findPos(row,k+x);
                    int r=p.first;
                    int c=p.second;
                    if(vis[r][c]!= -1) continue;
                    vis[r][c]=1;
                    if(board[r][c]== -1)
                    {
                        q.push(x+k);
                    }
                        
                    else
                    {
                        q.push(board[r][c]);
                    }
                }
                
            }
            steps++;
        }
        return -1;
        
    }
};