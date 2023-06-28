//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    queue<pair<int,pair<int,int>>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({0,{i,j}});
	                vis[i][j]=1;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int distance=q.front().first;
	        int r=q.front().second.first;
	        int c=q.front().second.second;
	        q.pop();
	        ans[r][c]=distance;
	        
	        for(int i= -1;i<=1;i++)
	        {
	            for(int j= -1;j<=1;j++)
	            {
	                if(abs(i)!=abs(j))
	                {
	                    int Newr=r+i;
	                    int Newc=c+j;
	                    
	                    if(Newr>=0 && Newr<n && Newc>=0 && Newc<m && !vis[Newr][Newc])
	                    {
	                        vis[Newr][Newc]=1;
	                        q.push({distance+1,{Newr,Newc}});
	                    }
	                }
	            }
	        }
	    }
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends