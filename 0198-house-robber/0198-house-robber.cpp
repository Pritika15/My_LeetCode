class Solution {
public:
    int solve(int indx,vector<int>& nums,vector<int>&dp)
    {
        if(indx<0) return -1e9;
//         Base Case
        if(indx==0) return nums[0];
        
        if(dp[indx]!=-1) return dp[indx];
//         Recursive function
        int take= -1e9;
        if(indx>1) take=nums[indx]+solve(indx-2,nums,dp);
        int notTake=0+solve(indx-1,nums,dp);
        
        return dp[indx]= max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        // return solve(n-1,nums,dp);
        dp[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            int take= nums[i];
            if(i>1) take+=dp[i-2];
            int notTake=0+dp[i-1];
            
            dp[i]=max(take,notTake);
        }
        
        return dp[n-1];
        
    }
};