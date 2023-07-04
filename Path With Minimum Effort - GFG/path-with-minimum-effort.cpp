//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dis[0][0]=0;
        
        while(!pq.empty())
        {
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            
            for(int i= -1;i<=1;i++)
            {
                for(int j= -1;j<=1;j++)
                {
                    if(abs(i)!=abs(j))
                    {
                        int Newr=r+i;
                        int Newc=c+j;
                        
                        if(Newr>=0 && Newr<n && Newc>=0 && Newc<m && dis[Newr][Newc]>d)
                        {
                            int diff=abs(heights[Newr][Newc]-heights[r][c]);
                            int maxD=max(d,diff);
                            if(diff<dis[Newr][Newc]) dis[Newr][Newc]=maxD;
                            pq.push({maxD,{Newr,Newc}});
                        }
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends