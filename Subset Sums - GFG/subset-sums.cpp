//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(int index,vector<int> arr, int N,vector<int>&ans,vector<int>&v)
    {
        if(index==N)
        {
            int sum=0;
            for(int i=0;i<v.size();i++)
            {
                sum+=v[i];
            }
            ans.push_back(sum);
            return;
            
        }
        v.push_back(arr[index]);
        solve(index+1,arr,N,ans,v);
        v.pop_back();
        solve(index+1,arr,N,ans,v);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        vector<int>v;
        solve(0,arr,N,ans,v);
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends