//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
                     int minPoss=n;
                     int city=-1;
                     
                     vector<vector<int>>dis(n,vector<int>(n,1e9));
                     for(int i=0;i<n;i++)
                     {
                         dis[i][i]=0;
                     }
                     for(int i=0;i<edges.size();i++)
                     {
                         int r=edges[i][0];
                         int c=edges[i][1];
                         int wt=edges[i][2];
                         
                         dis[r][c]=wt;
                         dis[c][r]=wt;
                     }
                     
                     for(int var=0;var<n;var++)
                     {
                         for(int i=0;i<n;i++)
                         {
                             for(int j=0;j<n;j++)
                             {
                                 if(dis[i][var]!= 1e9 || dis[var][j]!=1e9)
                                 {
                                     dis[i][j]=min(dis[i][j],dis[i][var]+dis[var][j]);
                                 }
                             }
                         }
                     }
                     
                     for(int i=0;i<n;i++)
                     {
                         int cnt=0;
                         for(int j=0;j<n;j++)
                         {
                             if(dis[i][j]<=distanceThreshold) cnt++;
                         }
                         if(minPoss>=cnt)
                         {
                             minPoss=cnt;
                             city=i;
                         }
                        
                        
                     }
                     return city;
                 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends