//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet
{
    public:
    vector<int>parent,size;
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    int findParent(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    
    void UnionBySize(int u, int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]>size[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
    
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>>graph;
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                if(adj[i][j]==1)
                {
                    graph.push_back({i,j});
                }
            }
        }
        DisjointSet ds(V);
        for(int i=0;i<graph.size();i++)
        {
            if(ds.findParent(graph[i][0])!=ds.findParent(graph[i][1]))
            {
                ds.UnionBySize(graph[i][0],graph[i][1]);
            }
        }
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            if(i==ds.parent[i]) cnt++;
            
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends