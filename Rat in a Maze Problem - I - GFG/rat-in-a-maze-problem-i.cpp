//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(int row, int col, string &s,vector<string>&ans,vector<vector<int>>&m,int n,vector<vector<int>>&vis)
    {
        if(row==n-1 && col==n-1)
        {
            ans.push_back(s);
            return;
        }
        vis[row][col]=1;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(abs(i)!=abs(j))
                {
                    int Newrow=row+i;
                    int Newcol=col+j;
                    
                    if(Newrow>=0 && Newrow<n && Newcol>=0 && Newcol<n && m[Newrow][Newcol]==1 && vis[Newrow][Newcol]==0)
                    {
                        if(i== -1) s.push_back('U');
                        else if(i== 1) s.push_back('D');
                        else if(j== -1) s.push_back('L');
                        else if(j== 1) s.push_back('R');
                        helper(Newrow,Newcol,s,ans,m,n,vis);
                         s.pop_back();
                    }
                }
                
            }
        }
      
                        vis[row][col]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>vis(n,vector<int>(n,0));
         vector<string> ans;
         string s;
         if(m[0][0]==0) return ans;
        helper(0,0,s,ans,m,n,vis);
         return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends