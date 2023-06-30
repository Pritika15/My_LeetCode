//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // Topological Sort--->To check cycle
        queue<int>q;
        vector<int>Indegree(V,0);
       
        for(int i=0;i<V;i++)
        {
            for(auto itr:adj[i])
            {
                Indegree[itr]++;
            }
        }
        
        for(int i=0;i<Indegree.size();i++)
        {
            if(Indegree[i]==0) q.push(i);
        }
        
        int cnt=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            cnt++;
            for(auto itr:adj[x])
            {
                Indegree[itr]--;
                if(Indegree[itr]==0) q.push(itr);
            }
        }
        if(cnt==V) return false;
        return true;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends