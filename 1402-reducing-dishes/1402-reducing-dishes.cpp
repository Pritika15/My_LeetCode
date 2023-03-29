class Solution {
public:
    int solve(int index, int time,vector<int>& satisfaction,vector<vector<int>>&dp)
    {
        if(index>=satisfaction.size()) 
            return 0;
        if(dp[index][time]!= -1) return dp[index][time];
        int include=satisfaction[index]*(time+1)+solve(index+1,time+1,satisfaction,dp);
        int exclude=0+solve(index+1,time,satisfaction,dp);
        return dp[index][time]=max(include,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1, -1));
        return solve(0,0,satisfaction,dp);
    }
};