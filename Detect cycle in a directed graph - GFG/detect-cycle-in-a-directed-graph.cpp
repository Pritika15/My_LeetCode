//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>Indegree(V);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                Indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(Indegree[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            ans.push_back(x);
            
            for(auto i:adj[x])
            {
                Indegree[i]--;
                if(Indegree[i]==0) q.push(i);
            }
        }
        if(ans.size()==V) return false;
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