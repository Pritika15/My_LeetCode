//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<char>>&vis)
    {
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int delRow=-1;delRow<=1;delRow++)
            {
                for(int delCol=-1;delCol<=1;delCol++)
                {
                    int newR=row+delRow;
                    int newC=col+delCol;
                    
                    if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]=='1' && !vis[newR][newC])
                    {
                        vis[newR][newC]=1;
                        q.push({newR,newC});
                    }
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        vector<vector<char>>vis(r,vector<char>(c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1'&& !vis[i][j])
                {
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends