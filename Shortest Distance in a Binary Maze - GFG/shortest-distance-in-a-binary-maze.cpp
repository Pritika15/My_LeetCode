//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({source.first,source.second});
        dis[source.first][source.second]=0;
        while(!pq.empty())
        {
            int r=pq.top().first;
            int c=pq.top().second;
            pq.pop();
            
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(abs(i)!=abs(j))
                    {
                        int Newr=r+i;
                        int Newc=c+j;
                        
                        if(Newr>=0 && Newr<n && Newc>=0 && Newc<m && dis[r][c]+1<dis[Newr][Newc] && grid[Newr][Newc]==1)
                        {
                            dis[Newr][Newc]=dis[r][c]+1;
                            pq.push({Newr,Newc});
                        }
                    }
                }
            }
        }
        if(dis[destination.first][destination.second]==1e9) return -1;
        return dis[destination.first][destination.second];
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends