//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisJoint{
    public:
    vector<int>parent,size;
    
    DisJoint(int n)
    {
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        
        size.resize(n,0);
        
    }
    
    int FindParent(int node)
    {
        if(node==parent[node]) return node;
        
        return parent[node]=FindParent(parent[node]);
    }
    
    void UnionBysize(int u, int v)
    {
        int ulp_u=FindParent(u);
        int ulp_v=FindParent(v);
        if(ulp_u==ulp_v) return;
        
        if(size[ulp_u]<size[ulp_v]) 
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        
    }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DisJoint DS(V);
        
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[0].size();j++)
            {
                if(adj[i][j]==1)
                {
                    DS.UnionBysize(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            if(DS.parent[i]==i) cnt++;
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