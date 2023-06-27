//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void solve(int indx,vector<int>adjList[],vector<int>&vis)
  {
      vis[indx]=1;
      for(auto itr:adjList[indx])
      {
          if(!vis[itr]) solve(itr,adjList,vis);
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>adjList[V];
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
                
                
            }
        }
        
        vector<int>vis(V,0);
        int ans=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                ans++;
                solve(i,adjList,vis);
            }
        }
        return ans;
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