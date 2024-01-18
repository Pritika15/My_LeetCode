class Solution {
public:
//     int climbStairdHelper(int n, vector<int>&dp)
//     {
// //         if(n==0 || n==1)
// //             return 1;
        
// //         if(dp[n]!= -1)
// //             return dp[n];
        
// //         return climbStairs(n-1)+climbStairs(n-2);
//         // dp[0]=1;
//         // dp[1]=1;
//         // for(int i=2;i<=n;i++)
//         // {
//         //     dp[i]=dp[i-1]+dp[i-2];
//         // }
//         // return dp[n];
//     }
    int climbStairs(int n) {
        
        // vector<int>dp(n+1, -1);
        // return climbStairdHelper(n,dp);
        
        int prevstep=1;
        int prev1step=1;
        
        for(int i=2;i<=n;i++)
        {
            int curr=prevstep+prev1step;
            prevstep=prev1step;
            prev1step=curr;
        }
        return prev1step;
    }
};