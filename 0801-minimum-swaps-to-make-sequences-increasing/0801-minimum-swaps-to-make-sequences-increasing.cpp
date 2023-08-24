class Solution {
public:
    int solve(int indx,vector<int>& nums1, vector<int>& nums2,int prev1,int prev2,vector<vector<int>>&dp,bool swap)
    {
        if(indx>=nums1.size()) return 0;
        if(dp[indx][swap]!= -1) return dp[indx][swap];
        int Swap=1e9,NotSwap=1e9;
        if(nums1[indx]> prev2 && nums2[indx] > prev1)
            Swap=1+solve(indx+1,nums1,nums2,nums2[indx],nums1[indx],dp,true);
       
       
        if(prev1<nums1[indx] && prev2<nums2[indx])
        {
            NotSwap=solve(indx+1,nums1,nums2,nums1[indx],nums2[indx],dp,false);
        }
                                                    
            
        
        
        return dp[indx][swap]=min(Swap,NotSwap);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
       vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
        return solve(0,nums1,nums2,-1,-1,dp,false);
    }
};