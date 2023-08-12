//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs(int node,vector<int>&vis,vector<int>&pathVis,vector<int>&check,vector<int> adj[])
  {
      vis[node]=1;
      pathVis[node]=1;
      
      for(auto it:adj[node])
      {
          if(!vis[it])
          {
              if(dfs(it,vis,pathVis,check,adj)==true) return true;
          }
          else if(vis[it] && pathVis[it]) return true;
      }
      pathVis[node]=0;
      check.push_back(node);
      return false;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>check;
        vector<int>vis(V,0),pathVis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,pathVis,check,adj);
            }
            
        }
        sort(check.begin(),check.end());
        return check;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends