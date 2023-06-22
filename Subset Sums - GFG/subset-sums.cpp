//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
     void solve(vector<int> &num,vector<vector<int>>&subSeq)
    {
      int n=num.size();
      for(int i=0;i<(1<<n);i++)
      {
        vector<int>temp;
        for(int j=0;j<n;j++)
        {
          if(i & (1<<j))
          {
            temp.push_back(num[j]);
          }
        }
        if (temp.size() > 0) {
          subSeq.push_back(temp);
          temp.clear();
        }
      }
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
      vector<vector<int>>subSeq;
      solve(arr,subSeq);
      vector<int>ans;
      ans.push_back(0);
      for(int i=0;i<subSeq.size();i++)
      {
        int t=0;
        for(int j=0;j<subSeq[i].size();j++)
        {
          t+=subSeq[i][j];
        }
        ans.push_back(t);
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