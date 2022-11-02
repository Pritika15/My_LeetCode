//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int>dp1(n,1),dp2(n,1);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(nums[i]>nums[j] && dp1[i]<1+dp1[j])
	            {
	                dp1[i]=1+dp1[j];
	            }
	        }
	       
	    } 
	   // for(int i=0;i<n;i++)
	   // cout<<dp1[i]<<" ";
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int j=n-1;j>i;j--)
	        {
	            if(nums[i]>nums[j] && dp2[i]< 1+dp2[j])
	            {
	                dp2[i]=1+dp2[j];
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        int temp=dp1[i]+dp2[i];
	        dp1[i]=temp-1;
	    }
	    int maxi=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        maxi=max(maxi,dp1[i]);
	    }
	    return maxi;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends