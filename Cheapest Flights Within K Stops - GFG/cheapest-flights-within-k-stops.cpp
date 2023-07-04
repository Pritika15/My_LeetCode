//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>>AdjList[n];
        for(int i=0;i<flights.size();i++)
        {
            int from=flights[i][0];
            int to=flights[i][1];
            int price=flights[i][2];
            
            AdjList[from].push_back({to,price});
        }
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>dis(n,1e9);
        dis[src]=0;
        pq.push({0,{src,0}}); //k,node,dis
        
        while(!pq.empty())
        {
            int k=pq.top().first;
            int node=pq.top().second.first;
            int d=pq.top().second.second;
            pq.pop();
            if(k>K) continue;
            // if(node==dst && k<K) continue;
            for(auto itr:AdjList[node])
            {
                int neighbor=itr.first;
                int wt=itr.second;
                
                if(d+wt<dis[neighbor])
                {
                    dis[neighbor]=d+wt;
                    pq.push({k+1,{neighbor,d+wt}});
                }
            }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends