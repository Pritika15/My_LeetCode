//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stack<string>st;
        int n=S.length();
        string temp="";
        for(int i=0;i<=n;i++)
        {
            
            if(S[i]=='.' || i==n)
            {
                temp.push_back('.');
                st.push(temp);
                temp="";
                
            }
            else
            {
                temp+=S[i];
            }
        }
        string ans;
        while(!st.empty())
        {
            string ss=st.top();
            st.pop();
            ans+=ss;
        }
        ans.pop_back();
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends