class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<vector<int>>q;
        if(grid[n-1][n-1]!=0 || grid[0][0]!=0) return -1;
        q.push({0,0,1}); // i,j,pathlength
        grid[0][0]=1;
        while(!q.empty())
        {
            vector<int>temp=q.front();
            q.pop();
            if(temp[0]==n-1 && temp[1]==n-1)
            {
                return temp[2];
            }
            for(int i=-1 ;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int a=temp[0]+i;
                    int b=temp[1]+j;
                    if(a>=0 && a<n && b>=0 && b<n && grid[a][b]==0)
                    {
                        grid[a][b]=1;
                        q.push({a,b,temp[2]+1});
                    }
                }
            }
        }
        return -1;
        
    }
};