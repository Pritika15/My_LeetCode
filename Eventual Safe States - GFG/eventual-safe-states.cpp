//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs(int indx,vector<int>adj[],vector<int>&vis,vector<int>&PathVis,vector<int>&check)
  {
      vis[indx]=1;
      PathVis[indx]=1;
      
      for(auto itr:adj[indx])
      {
          if(!vis[itr])
          {
              if(dfs(itr,adj,vis,PathVis,check)==true)
              {
                  check[itr]=0;
                  return true;
              }
          }
          else if(PathVis[itr])
          {
              check[itr]=0;
              return true;
          }
      }
      check[indx]=1;
      PathVis[indx]=0;
      return false;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>ans;
        vector<int>vis(V,0);
        vector<int>PathVis(V,0);
        vector<int>check(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,PathVis,check);
            }
        }
        for(int i=0;i<check.size();i++)
        {
            if(check[i]==1)
            {
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
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