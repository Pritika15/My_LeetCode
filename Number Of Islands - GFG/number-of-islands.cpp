//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
    
    void UnionBySize(int u, int v)
    {
        int ulp_u = FindParent(u);
        int ulp_v= FindParent(v);
        
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int> ans;
        DisJoint ds(n*m);
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
       for(auto it:operators)
       {
           int row=it[0];
           int col=it[1];
            if(vis[row][col])
                {ans.push_back(cnt);
                    continue;
                }
                vis[row][col]=1;
                cnt++;
                
                for(int k= -1;k<=1;k++)
                {
                    for(int l= -1;l<=1; l++)
                    {
                        if(abs(k)!=abs(l))
                        {
                            int Newi=row+k;
                            int Newj=col+l;
                            
                            if(Newi>=0 && Newi<n && Newj>=0 && Newj<m)
                            {
                                if(vis[Newi][Newj])
                                {
                                    int node=row*m+col;
                                    int adjNode=Newi*m+Newj;
                                    
                                    if(ds.FindParent(node)!=ds.FindParent(adjNode))
                                    {
                                        cnt--;
                                        ds.UnionBySize(node,adjNode);
                                       
                                    }
                                }
                                
                            }
                        }
                        
                    }
                }
                ans.push_back(cnt); 
       }
               
            
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends