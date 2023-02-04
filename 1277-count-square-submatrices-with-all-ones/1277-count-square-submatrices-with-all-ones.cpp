class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>dp(r,vector<int>(c,0));
        for(int i=0;i<c;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int j=0;j<r;j++)
        {
            dp[j][0]=matrix[j][0];
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(matrix[i][j]==1)
                {
                    dp[i][j]=min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
                else
                    dp[i][j]=0;
            }
        }
        int ans=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                ans+=dp[i][j];
                //cout<<i<<" "<<j;
            }
           // cout<<endl;
        }
        return ans;
    }
};