class Solution {
public:
//     int solve(int i,vector<int>& nums,vector<int>&dp)
//     {
//         if(i==0) return nums[0];
//         if(i<0) return 0;
//         if(dp[i]!= -1) return dp[i];
//         // int take=INT_MIN;
//         int take=nums[i]+solve(i-2,nums,dp);
//         int notTake=0+solve(i-1,nums,dp);
//         return dp[i]=max(take,notTake);
        
//     }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int>dp(n+1,-1);
        // return solve(n-1,nums,dp);
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int take=nums[i];
            if(i>1) take+=dp[i-2];
            int notTake=dp[i-1];
            
            dp[i]=max(take,notTake);
        }
        return dp[n-1];
    }
};