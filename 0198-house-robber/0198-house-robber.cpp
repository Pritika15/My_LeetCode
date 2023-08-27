class Solution {
public:
    int solve(int indx,vector<int>& nums,int n,vector<int>&dp)
    {
        if(indx>=n) return 0;
        if(dp[indx]!= -1) return dp[indx];
        int notPick=solve(indx+1,nums,n,dp);
        int Pick=nums[indx]+solve(indx+2,nums,n,dp);
        
        return dp[indx]=max(notPick,Pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,n,dp);
    }
};