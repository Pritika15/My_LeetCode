//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>>ans(n,vector<char>(m,'X'));
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<pair<int,int>>q;
        //First row
        for(int j=0;j<m;j++)
        {
            if(mat[0][j]=='O')
            {
                q.push({0,j});
                vis[0][j]=1;
            }
        }
        //Last row
        for(int j=0;j<m;j++)
        {
            if(mat[n-1][j]=='O')
            {
                q.push({n-1,j});
                vis[n-1][j]=1;
            }
        }
        //First col
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O')
            {
                q.push({i,0});
                vis[i][0]=1;
            }
        }
        //Last col
        
        for(int i=0;i<n;i++)
        {
            if(mat[i][m-1]=='O')
            {
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            ans[r][c]='O';
            
            for(int i= -1;i<=1;i++)
            {
                for(int j= -1;j<=1; j++)
                {
                    if(abs(i)!=abs(j))
                    {
                        int Newr=r+i;
                        int Newc=c+j;
                        
                        if(Newr>=0 && Newr<n && Newc>=0 && Newc<m && !vis[Newr][Newc] && mat[Newr][Newc]=='O')
                        {
                            q.push({Newr,Newc});
                            vis[Newr][Newc]=1;
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
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends