class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 1;
        vector<int>dp(n,-1);
        for(int i =0;i<n;i++)
        {
            ans = max(ans,solve(arr,d,i,dp));
        }
        return ans;
    }

    int solve(vector<int>& arr, int d,int i, vector<int>&dp)
    {
        if(dp[i]!= -1) return dp[i];

        int maxAns = 1;

        for(int j= i+1;j-i<=d && j<arr.size();j++)
        {
            if(arr[j]<arr[i]) maxAns = max(maxAns,1+ solve(arr,d,j,dp));
            else break;
        }

        for( int j= i-1;abs(j-i)<=d && j>=0;j--)
        {
            if(arr[j]<arr[i]) maxAns = max(maxAns,1+ solve(arr,d,j,dp));
            else break;
        }

        return dp[i]= maxAns;
    }
};