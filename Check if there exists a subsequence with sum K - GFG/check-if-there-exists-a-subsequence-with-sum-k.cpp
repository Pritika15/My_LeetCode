//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool helper(int index,int n, vector<int>& arr, int k,vector<vector<int>>&dp)
    {
        if(k==0) return true;
        if(index==0)
        {
            return (arr[index]==k);
        }
        if(dp[index][k]!= -1) return dp[index][k];
        bool nottake=helper(index-1,n,arr,k,dp);
        bool take=false;
        if(arr[index]<=k)
        {
            take=helper(index-1,n,arr,k-arr[index],dp);
        }
        return dp[index][k]=nottake | take;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return helper(n-1,n,arr,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends