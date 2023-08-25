class Solution {
public:
    int solve(int indx,vector<int>& satisfaction,int t,vector<vector<int>>&dp)
    {
        if(indx>=satisfaction.size()) return 0;
        if(dp[indx][t]!= -1) return dp[indx][t];
        int NotPick=solve(indx+1,satisfaction,t,dp);
        int Pick=satisfaction[indx]*t+solve(indx+1,satisfaction,t+1,dp);
        
        return dp[indx][t]=max(NotPick,Pick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        
        return solve(0,satisfaction,1,dp);
    }
};