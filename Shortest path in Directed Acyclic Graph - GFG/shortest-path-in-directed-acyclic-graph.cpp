//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void TopoSort(int indx,vector<pair<int,int>>AdjList[],vector<int>&vis,stack<int>&s)
  {
      vis[indx]=1;
      for(auto itr:AdjList[indx])
      {
          if(!vis[itr.first])
          {
              TopoSort(itr.first,AdjList,vis,s);
          }
      }
      s.push(indx);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        // AdjList formation
        vector<pair<int,int>>AdjList[N];
        for(int i=0;i<M;i++)
        {
            AdjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        // TopoSort
        stack<int>s;
        vector<int>dis(N,1e9);
        vector<int>vis(N,0);
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                TopoSort(i,AdjList,vis,s);
            }
        }
        dis[0]=0;
        while(!s.empty())
        {
            int x=s.top();
            s.pop();
            for(auto it:AdjList[x])
            {
                int v=it.first;//neighbor
                int wt=it.second;
                if(dis[x]+wt<dis[v])
                {
                    dis[v]=dis[x]+wt;
                }
            }
            
        }
        for(int i=0;i<dis.size();i++)
        {
            if(dis[i]==1e9) dis[i]= -1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends