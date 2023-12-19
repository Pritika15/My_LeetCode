class Solution {
public:
    int solve(int i,vector<int>& nums,int lastIndex,vector<vector<int>>&dp)
    {
        if(i==nums.size()) return 0;
        if(dp[i][lastIndex+1]!= -1) return dp[i][lastIndex+1];
        int take=-1e9;
        if(lastIndex== -1 || nums[lastIndex]<nums[i]) take=1+solve(i+1,nums,i,dp);
        int notTake=solve(i+1,nums,lastIndex,dp);
        return dp[i][lastIndex+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,nums,-1,dp);
    }
};