//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        vector<long long>aa;
        vector<long long>bb;
        for(int i=0;i<n;i++)
        {
            aa.push_back(a[i]);
            bb.push_back(b[i]);
        }
        sort(aa.begin(),aa.end());
        sort(bb.begin(),bb.end(),greater<int>());
        for(int i=0;i<n;i++)
        {
            if(aa[i]+bb[i]<k)
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        long long a[n + 2], b[n + 2];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        Solution ob;
        cout << ob.isPossible(a, b, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends