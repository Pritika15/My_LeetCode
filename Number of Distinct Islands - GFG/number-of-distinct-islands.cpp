//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int r, int c,vector<vector<int>>& grid,vector<vector<int>>&vis,vector<pair<int,int>>&vec,int baseR,int baseC)
  {
      vis[r][c]=1;
      vec.push_back({r-baseR,c-baseC});
      int n=grid.size();
      int m=grid[0].size();
      
      for(int i=-1;i<=1;i++)
      {
          for(int j=-1;j<=1;j++)
          {
              if(abs(i)!=abs(j))
              {
                  int Newr=r+i;
                  int Newc=c+j;
                  
                  if(Newr>=0 && Newr<n && Newc>=0 && Newc<m && !vis[Newr][Newc] && grid[Newr][Newc]==1 )
                  {
                      dfs(Newr,Newc,grid,vis,vec,baseR,baseC);
                  }
              }
          }
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                   vector<pair<int,int>>vec;
                   dfs(i,j,grid,vis,vec,i,j);
                   st.insert(vec);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends