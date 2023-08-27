class Solution {
public:
    int solve(int indx,vector<int>& nums,vector<int>&dp)
    {
        if(indx==0) return nums[0];
        if(indx<0) return 0;
        if(dp[indx]!= -1)return dp[indx];
        int notPick=solve(indx-1,nums,dp);
        int Pick=nums[indx]+solve(indx-2,nums,dp);
        
        return dp[indx]=max(notPick,Pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>v1,v2;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0) v2.push_back(nums[i]);
            if(i!=n-1) v1.push_back(nums[i]);
        }
        vector<int>dp1(v1.size(),-1);
        vector<int>dp2(v2.size(),-1);
        return max(solve(v1.size()-1,v1,dp1),solve(v2.size()-1,v2,dp2));
    }
};