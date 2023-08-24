//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        unordered_map<char,int>m1;
        for(int i=0;i<str1.length();i++)
        {
            m1[str1[i]]++;
        }
        unordered_map<char,int>m2;
        for(int i=0;i<str2.length();i++)
        {
            m2[str2[i]]++;
        }
        if(m1.size()!=m2.size()) return false;
        // return true;
        unordered_map<char,char>m;
        int n1=str1.length();
        int n2=str2.length();
        if(n1!=n2) return false;
        
        for(int i=0;i<n1;i++)
        {
            if(m.find(str1[i])==m.end())
            {
                m[str1[i]]=str2[i];
            }
            else
            {
                if(m[str1[i]]!= str2[i]) return false;
            }
        }
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends