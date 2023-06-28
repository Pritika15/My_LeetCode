//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        queue<pair<int,int>>q;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                q.push({i,-1});
                vis[i]=1;
                while(!q.empty())
                {
                    int NodeVal=q.front().first;
                    int parent= q.front().second;
                    q.pop();
                    
                    for(auto itr:adj[NodeVal])
                    {
                        if(itr!=parent && vis[itr])
                        {
                            return true;
                        }
                        if(!vis[itr])
                        {
                            q.push({itr,NodeVal});
                            vis[itr]=1;
                        }
                    }
                }
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