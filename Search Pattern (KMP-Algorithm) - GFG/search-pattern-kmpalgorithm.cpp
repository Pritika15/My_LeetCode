//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            int n=pat.length();
            vector<int>Prefix(n,0);
            for(int i=1;i<n;i++)
            {
                int j=Prefix[i-1];
                
                while(j>0 && pat[i]!=pat[j]) j=Prefix[j-1];
                
                if(pat[i]==pat[j]) j++;
                
                Prefix[i]=j;
            }
            
            vector<int>ans;
            int i=0,j=0;
            while(i<txt.length())
            {
                if(pat[j]==txt[i])
                {
                    i++;
                    j++;
                }
                else
                {
                    
                    if(j!=0)
                    {
                        j=Prefix[j-1];
                    }
                    else
                    {
                        i++;
                    }
                }
                
                if(j==n)
                {
                    ans.push_back(i-n+1);
                }
            }
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
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends