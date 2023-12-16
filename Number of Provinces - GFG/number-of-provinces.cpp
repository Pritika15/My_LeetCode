//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int curr,vector<int>&vis,vector<int>adjList[])
  {
      vis[curr]=1;
      for(auto itr:adjList[curr])
      {
          if(!vis[itr])
          {
              dfs(itr,vis,adjList);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>adjList[V+1];
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[0].size();j++)
            {
                if(adj[i][j]==1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int>vis(V,0);
       for(int i=0;i<V;i++)
       {
           if(!vis[i])
           {
               dfs(i,vis,adjList);
               cnt++;
           }
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