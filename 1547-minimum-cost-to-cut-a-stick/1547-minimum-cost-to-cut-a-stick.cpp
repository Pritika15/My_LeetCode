class Solution {
public:
    // int solve(int i, int j, int n, vector<int>& cuts,vector<vector<int>>&dp)
    // {
    //     if(i>j) return 0;
    //     if(dp[i][j]!= -1) return dp[i][j];
    //     int mini=INT_MAX;
    //     for(int k=i;k<j;k++)
    //     {
    //         int cost=cuts[j+1]-cuts[i-1]+solve(i,k,n,cuts,dp)+solve(k+1,j,n,cuts,dp);
    //         mini=min(mini,cost);
    //     }
    //     return dp[i][j]=mini;
    // }
    int dp[101][101];
    
    int mincost(int start, int end, vector<int>& cuts, int cuts_start, int cuts_end)
    {
        if(cuts_start>cuts_end)
            return 0;
        
        if(dp[cuts_start][cuts_end]!=-1)
            return dp[cuts_start][cuts_end];
        
        int minimum = INT_MAX;
        for(int i=cuts_start; i<=cuts_end; i++)
            minimum = min(minimum, (end-start)+mincost(start, cuts[i], cuts, cuts_start, i-1)+mincost(cuts[i], end, cuts, i+1, cuts_end));
        
        return dp[cuts_start][cuts_end] = minimum;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        //vector<vector<int>>dp(n,vector<int>(n, -1));
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        
        //return solve(1,n-1,n,cuts,dp);
        return mincost(0,n,cuts,0,cuts.size()-1);
    }
};