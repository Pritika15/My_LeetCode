//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    void solve(string pat, string txt,vector<int>&ans,int q)
    {
        int d=256;
        int m=pat.length();
        int n=txt.length();
        int p=0;
        int t=0;
        int h=1;
        
        for(int i=0;i<m-1;i++)
        {
            h=(h*d)%q;
        }
        for(int i=0;i<m;i++)
        {
            p=(p*d+pat.at(i))%q;
            t=(t*d+txt.at(i))%q;
        }
        
        for(int i=0;i<=n-m;i++)
        {
            if(t==p)
            {
                int j;
                for(j=0;j<m;j++)
                {
                    if(pat.at(j)!=txt.at(j+i)) break;
                }
                
                if(j==m) ans.push_back(i+1);
            }
            
            if(i<n-m)
            {
                t=(d*(t-txt.at(i)*h)+txt.at(i+m))%q;
                if(t<0) t=t+q;
            }
        }
    }
        vector <int> search(string pat, string txt)
        {
            //code here.
            vector <int> ans;
            solve(pat,txt,ans,101);
            if(ans.size()==0) return {-1};
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends