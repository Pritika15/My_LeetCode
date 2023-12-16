//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int r, int c,vector<vector<char>>& grid,vector<vector<int>>&vis)
    {
        vis[r][c]=1;
        
        for(int i= -1;i<=1;i++)
        {
            for(int j= -1;j<=1;j++)
            {
                int newr=r+i;
                int newc=c+j;
                
                if(newr>=0 && newc>=0 && newr<grid.size() && newc<grid[0].size() && grid[newr][newc]=='1' && !vis[newr][newc])
                {
                    dfs(newr,newc,grid,vis);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
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