//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void bfs(int r,int c,vector<vector<int>>& image,vector<vector<int>>& ans,int newColor, int iniCol)
{
    ans[r][c]=newColor;
    queue<pair<int,int>>q;
    q.push({r,c});
    int n=image.size();
    int m=image[0].size();
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(abs(i)!= abs(j))
                {
                    int Newrow=row+i;
                    int Newcol=col+j;
                    
                    if(Newrow>=0 && Newrow<n && Newcol>=0 && Newcol<m && image[Newrow][Newcol]==iniCol && ans[Newrow][Newcol]!=newColor)
                    {
                        ans[Newrow][Newcol]= newColor;
                        q.push({Newrow,Newcol});
                    }
                }
            }
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
         vector<vector<int>> ans=image;
         int iniCol=image[sr][sc];
         bfs(sr,sc,image,ans,newColor,iniCol);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends