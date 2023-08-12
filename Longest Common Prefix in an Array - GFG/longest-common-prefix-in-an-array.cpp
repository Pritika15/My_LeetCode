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
        sort(arr,arr+N);
        string s1=arr[0];
        string s2=arr[N-1];
        int len=min(s1.length(),s2.length());
        string ans;
        for(int i=0;i<len;i++)
        {
            if(s1[i]==s2[i]) ans+=s1[i];
            else break;
            
        }
        if(ans.length()==0) return "-1";
        return ans;
        
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