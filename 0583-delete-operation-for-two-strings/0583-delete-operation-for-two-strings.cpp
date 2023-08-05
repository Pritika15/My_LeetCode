class Solution {
public:
    int minDistance(string word1, string word2) {
    int n1=word1.length();
    int n2= word2.length();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    int maxi=0;

    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if( word1[i-1]== word2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            maxi=max(maxi,dp[i][j]);
        }
    }
    return n1+n2-(2*maxi);
    }
};