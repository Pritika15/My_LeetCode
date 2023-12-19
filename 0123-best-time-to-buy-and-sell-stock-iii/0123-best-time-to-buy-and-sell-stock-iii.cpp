class Solution {
public:
    int solve(int i,vector<int>& prices,int buy,int cnt,vector<vector<vector<int>>>&dp)
    {
        if(cnt==2)
        {
            return 0;
        }
        if(i>=prices.size()) return 0;
        if(dp[i][buy][cnt]!= -1) return dp[i][buy][cnt];
        int profit=0;
        if(buy)
        {
            profit=max(-prices[i]+solve(i+1,prices,0,cnt,dp),solve(i+1,prices,1,cnt,dp));
        }
        else
        {
            profit=max(prices[i]+solve(i+1,prices,1,cnt+1,dp),solve(i+1,prices,0,cnt,dp));
        }
        return dp[i][buy][cnt]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,prices,1,0,dp);
    }
};