class Solution {
public:
//     int solve(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>&dp)
//     {
//         if(j<0 || j>=matrix[0].size())
//             return 1e8;
//         if(i==0)
//             return matrix[i][j];
//         if(dp[i][j]!= -1)
//             return dp[i][j];
        
//             int up=matrix[i][j]+solve(i-1,j,matrix,dp);
//             int leftD=matrix[i][j]+solve(i-1,j-1,matrix,dp);
//             int rightD=matrix[i][j]+solve(i-1,j+1,matrix,dp);
           
            
        
//         return dp[i][j]=min(up,min(rightD,leftD));
//     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
//         int mini=1e8;
//         vector<vector<int>>dp(m,vector<int>(n, 0));
        
//         // for(int j=0;j<n;j++)
//         // {
//         //     mini=min(mini,solve(m-1,j,matrix,dp));
//         // }
//         // return mini;
//         for(int j=0;j<n;j++)
//         {
//             dp[0][j]=matrix[0][j];
//         }
        
//         for(int i=1;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
               
//                 int leftD=1e9,rightD=1e9;
//                 int up=matrix[i][j]+dp[i-1][j];
                 
//                 if(j-1 >=0)
//                 {
//                     leftD=matrix[i][j]+dp[i-1][j-1];
//                 }
                
               
//                    if(j+1<n)
//                    {
//                        rightD=matrix[i][j]+dp[i-1][j+1];
//                    }
                    
//                    dp[i][j] =min(up,min(leftD,rightD));
               
                
//             }
//         }
//         mini=1e8;
//         for(int j=0;j<n;j++)
//         {
//             mini=min(mini,dp[m-1][j]);
//         }
//         return mini;
        vector<int>prev(n,0);
        for(int j=0;j<n;j++)
        {
            prev[j]=matrix[0][j];
        }
        for(int i=1;i<m;i++)
        {
            vector<int>curr(n,0);
            for(int j=0;j<n;j++)
            {
                int leftD=1e9,rightD=1e9;
                int up=matrix[i][j]+prev[j];
                if(j-1>=0)
                    leftD=matrix[i][j]+prev[j-1];
                
                if(j+1<n)
                    rightD=matrix[i][j]+prev[j+1];
                curr[j]=min(up,min(leftD,rightD));
            }
            prev=curr;
        }
        int mini=1e9;
        for(int j=0;j<n;j++)
        {
            mini=min(mini,prev[j]);
        }
        return mini;
    }
};