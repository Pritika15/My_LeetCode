//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string encryptString(string S) {
        // code here
        // unordered_map<int,string>m;
        // m[10]='a';
        // m[11]='b';
        // m[12]='c';
        // m[13]='d';
        // m[14]='e';
        // m[15]='f';
        int cnt=1;
        char ch=S[0];
        string ans;
        for(int i=1;i<S.length();i++)
        {
            if(S[i-1]==S[i]) cnt++;
            else
            {
                
                ans+=ch;
                string hex="";
                while(cnt!=0)
                {
                    int rem=cnt%16;
                    if(rem<10)
                    {
                        hex+=('0'+rem);
                    }
                    else
                    {
                        hex+=('a'+(rem-10));
                    }
                    cnt=cnt/16;
                }
                ans+=hex;
                ch=S[i];
                cnt=1;
            }       
           
            
        }
        ans+=ch;
        string hex="";
        while(cnt!=0)
        {
            int rem=cnt%16;
            if(rem<10)
            {
                hex+=('0'+rem);
            }
            else
            {
                hex+=('a'+(rem-10));
            }
            cnt=cnt/16;
        }
        ans+=hex;
        
       
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.encryptString(S)<<endl;
    }
    return 0;
}
// } Driver Code Ends