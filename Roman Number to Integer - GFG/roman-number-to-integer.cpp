//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        
        vector<int>num;
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            if(m.find(str[i])!=m.end())
            {
                num.push_back(m[str[i]]);
            }
        }
       int ans=0;
       for(int i=0;i<num.size()-1;i++)
       {
           if(num[i]>=num[i+1])
           {
               ans+=num[i];
           }
           else
           {
               ans-=num[i];
           }
       }
       ans+=num[num.size()-1];
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends