//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Disjoint{
    public:
    vector<int>parent,size;
    
    Disjoint(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        
        size.resize(n,0);
    }
    
    int FindParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        
        return parent[node]=FindParent(parent[node]);
        
    }
    
    void UnionBySize(int u, int v)
    {
        int ulp_u= FindParent(u);
        int ulp_v=FindParent(v);
        
        if(ulp_u==ulp_v) return;
        
        if(size[ulp_u] > size[ulp_v])
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
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        Disjoint Ds(n);
        int ExtraEdge=0;
        for(int i=0;i<edge.size();i++)
        {
            int u=edge[i][0];
            int v=edge[i][1];
            if(Ds.FindParent(u)==Ds.FindParent(v)) ExtraEdge++;
            else Ds.UnionBySize(u,v);
        }
        
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(Ds.parent[i]==i) cnt++;
        }
       if(cnt-1<=ExtraEdge) return cnt-1;
        
       else return -1;
        
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

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends