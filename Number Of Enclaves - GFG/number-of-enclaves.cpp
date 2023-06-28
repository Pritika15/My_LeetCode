//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        //first row
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1)
            {
                q.push({0,j});
                vis[0][j]=1;
            }
        }
        //last row
        for(int j=0;j<m;j++)
        {
            if(grid[n-1][j]==1)
            {
                q.push({n-1,j});
                vis[n-1][j]=1;
            }
        }
        // first col
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
                vis[i][0]=1;
            }
        }
        //last col
        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1])
            {
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            grid[r][c]=0;
            for(int i= -1;i<=1;i++)
            {
                for(int j= -1;j<=1;j++)
                {
                    if(abs(i)!=abs(j))
                    {
                        int Newr=r+i;
                        int Newc=c+j;
                        
                        if(Newr>=0 && Newr<n && Newc>=0 && Newc<m && !vis[Newr][Newc] && grid[Newr][Newc]==1)
                        {
                            vis[Newr][Newc]=1;
                            q.push({Newr,Newc});
                        }
                    }
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends