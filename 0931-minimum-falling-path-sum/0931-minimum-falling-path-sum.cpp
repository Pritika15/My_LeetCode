class Solution {
public:
//     int solve(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>&dp)
//     {
// //         Edge cases
        
//         if(j<0 || j>=matrix.size()) return 1e9;
// //         Termination case
//         if(i==0) return matrix[0][j];
        
// //         memoization
//         if(dp[i][j]!=-1) return dp[i][j];
// //         Recursive function
//         int UpperLD=matrix[i][j]+solve(i-1,j-1,matrix,dp);
//         int Upper=matrix[i][j]+solve(i-1,j,matrix,dp);
//         int UpperRD=matrix[i][j]+solve(i-1,j+1,matrix,dp);
        
//         return dp[i][j]=min(UpperLD,min(Upper,UpperRD));
//     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini=1e9;
        int n=matrix.size();
        
        vector<int>prev(n,0);
        for(int j=0;j<n;j++)
        {
            prev[j]=matrix[0][j];
        }
        
        for(int i=1;i<n;i++)
        {
            vector<int>curr(n,0);
            for(int j=0;j<n;j++)
            {
                int Upper=matrix[i][j]+prev[j];
                int UpperRD=1e9,UpperLD=1e9;
                if(j<n-1) UpperRD=matrix[i][j]+prev[j+1];
                if(j>0) UpperLD=matrix[i][j]+prev[j-1];
                
                curr[j]=min(Upper,min(UpperRD,UpperLD));
            }
            prev=curr;
        }
        
        for(int j=0;j<n;j++)
        {
            mini=min(mini,prev[j]);
        }
        
        return mini;
        
        
        
        
        
        
        
        
        
        
        // vector<vector<int>>dp(n,vector<int>(n,0));
        // for(int j=0;j<n;j++)
        // {
        //     mini=min(mini,solve(n-1,j,matrix,dp));
        // }
        // return mini;
        
//         for(int j=0;j<n;j++)
//         {
//             dp[0][j]=matrix[0][j];
//         }
        
//         for(int i=1;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
                
//                 int Upper=matrix[i][j]+dp[i-1][j];
//                 int UpperRD=1e9,UpperLD=1e9;
//                 if(j<n-1) UpperRD=matrix[i][j]+dp[i-1][j+1];
//                 if(j>0) UpperLD=matrix[i][j]+dp[i-1][j-1];
                
//                 dp[i][j]=min(Upper,min(UpperRD,UpperLD));
//             }
//         }
        
//         for(int j=0;j<n;j++)
//         {
//             mini=min(mini,dp[n-1][j]);
//         }
        
//         return mini;
    }
};