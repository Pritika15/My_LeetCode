class Solution {
public:
    int solve(int i, int j, string word1, string word2,vector<vector<int>>&dp)
    {
        if(i<0)
        {
            return j+1;
        }
        if(j<0) return i+1;
       if(dp[i][j]!= -1)return dp[i][j];
        int replace=1e9,del=1e9,insert=1e9,noOp=1e9;
        if(word1[i]==word2[j]) noOp=solve(i-1,j-1,word1,word2,dp);
        else
        {
            insert=1+solve(i,j-1,word1,word2,dp);
            del=1+solve(i-1,j,word1,word2,dp);
            replace=1+solve(i-1,j-1,word1,word2,dp);
            
        }
        return dp[i][j]=min(noOp,min(insert,min(del,replace)));
        
    }
    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,word1,word2,dp);
    }
};