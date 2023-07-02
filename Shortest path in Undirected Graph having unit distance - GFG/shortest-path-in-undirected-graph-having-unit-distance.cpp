//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
 
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
         vector<int>ans(N,INT_MAX);
         vector<int>AdjList[N];
         for(int i=0;i<edges.size();i++)
         {
             int u=edges[i][0];
             int v=edges[i][1];
             if(u!=v)
             {
                 AdjList[u].push_back(v);
                 AdjList[v].push_back(u);
             }
             
         }
         vector<int>vis(N,0);
         int sum=0;
         ans[src]=sum;
         queue<int>q;
         q.push(src);
         vis[src]=1;
         while(!q.empty())
         {
             int node=q.front();
             q.pop();
             
             for(auto it:AdjList[node])
             {
                 
                 if(!vis[it])
                 {
                     if(ans[node]+1<ans[it])
                     {
                         ans[it]=ans[node]+1;
                     }
                     q.push(it);
                     vis[it]=1;
                 }
                
             }
         }
         for(int i=0;i<ans.size();i++)
         {
             if(ans[i]==INT_MAX)
             ans[i]= -1;
         }
         return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends