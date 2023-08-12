//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        if(N==1) return arr[0];
        string temp;
        string s1=arr[0];
        string s2=arr[1];
        int l=min(s1.length(),s2.length());
        for(int i=0;i<l;i++)
        {
            if(s1[i]==s2[i]) temp+=s1[i];
            else break;
        }
        
        for(int i=2;i<N;i++)
        {
            string tt=arr[i];
            int len=min(tt.length(),temp.length());
            string ttt;
            
            for(int j=0;j<len;j++)
            {
                if(tt[j]==temp[j]) ttt+=tt[j];
                // if(j==len-1) temp=ttt;
                if(tt[j]!=tt[j] || j==len-1) 
                {
                    temp=ttt;
                    break;
                }
            }
            
        }
        if(temp.length()==0) return "-1";
        return temp;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends