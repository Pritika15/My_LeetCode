class Solution {
public:
    bool IsPossible(int row, int col, vector<vector<int>>& cells,int mid)
    {
        vector<vector<int>>vis(row,vector<int>(col,0));
        for(int i=0;i<mid;i++)
        {
            vis[cells[i][0]-1][cells[i][1]-1]=1;
        }
        queue<pair<int,int>>q;
        for(int i=0;i<col;i++)
        {
            if(vis[0][i]==0)
            {q.push({0,i});
             vis[0][i]=1;
            }
        }
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r==row-1) return true;
            for(int kk =-1;kk<=1;kk++)
            {
                for(int ll= -1;ll<=1;ll++)
                {
                    if(abs(kk)!=abs(ll))
                    {
                        int Newr=r+kk;
                        int Newc=c+ll;
                        
                        if(Newr>=0 && Newr<row && Newc>=0 && Newc<col && vis[Newr][Newc]==0)
                        {
                            q.push({Newr,Newc});
                            vis[Newr][Newc]=1;
                        }
                    }
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans=0, left=1,right=cells.size();
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(IsPossible(row,col,cells,mid))
            {
                ans=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        return ans;
    }
};