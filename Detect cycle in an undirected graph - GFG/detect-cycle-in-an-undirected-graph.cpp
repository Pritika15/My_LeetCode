//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int parent,vector<int> adj[],vector<int>&vis)
    {
        vis[node]=1;
        for(auto adjNodes:adj[node])
        {
            if(!vis[adjNodes])
            {
                if(dfs(adjNodes,node,adj,vis)==true) 
                return true;
            }
            else if(adjNodes!=parent) return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
       for(int i=0;i<V;i++)
       {
           if(!vis[i])
           {
               if(dfs(i,-1,adj,vis)==true) return true;
           }
       }
       return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends