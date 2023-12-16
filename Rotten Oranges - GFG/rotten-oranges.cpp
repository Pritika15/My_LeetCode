//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!vis[i][j] && grid[i][j]==2)
                {
                    q.push({i,{j,0}});
                    vis[i][j]=2;
                }
            }
        }
        int t=0;
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second.first;
            int timeval=q.front().second.second;
            t=max(timeval,t);
            q.pop();
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(abs(i)!=abs(j))
                    {
                        int newr=r+i;
                        int newc=c+j;
                        
                        if(newr>=0 && newc>=0 && newr<grid.size() && newc<grid[0].size() && !vis[newr][newc] && grid[newr][newc]==1)
                        {
                            q.push({newr,{newc,timeval+1}});
                            vis[newr][newc]=2;
                        }
                    }
                }
            }
        }
        for(int i=0;i<vis.size();i++)
        {
            for(int j=0;j<vis[0].size();j++)
            {
                if(vis[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }
        return t;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends