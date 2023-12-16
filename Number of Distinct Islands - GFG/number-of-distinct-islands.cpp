//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        map<vector<pair<int,int>>,int>AllCombs;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    q.push({i,j});
                    vis[i][j]=1;
                    vector<pair<int,int>>v;
                    while(!q.empty())
                    {
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        v.push_back({r-i,c-j});
                        for(int i= -1;i<=1;i++)
                        {
                            for(int j= -1;j<=1;j++)
                            {
                                if(abs(i)!=abs(j))
                                {
                                    int newr=r+i;
                                    int newc=c+j;
                                    
                                    if(newr>=0 && newc>=0 && newr<n && newc<m && grid[newr][newc]==1 && !vis[newr][newc])
                                    {
                                        q.push({newr,newc});
                                        vis[newr][newc]=1;
                                    }
                                }
                            }
                        }
                    }
                    if(AllCombs.find(v)==AllCombs.end())
                    {
                        AllCombs.insert({v,1});
                    }
                    else
                    AllCombs[v]++;
                }
            }
            
        }
        return AllCombs.size();
        
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