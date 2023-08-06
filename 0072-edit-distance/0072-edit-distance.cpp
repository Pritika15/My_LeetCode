class Solution {
public:
    int solve(int indx1, int indx2,string word1, string word2,vector<vector<int>>&dp)
    {
        if(indx1<0)
        {
            return indx2+1;
            
        }
        if(indx2<0) return indx1+1;
        if(dp[indx1][indx2]!= -1) return dp[indx1][indx2];
        if(word1[indx1]==word2[indx2]) return dp[indx1][indx2]= 0+solve(indx1-1,indx2-1,word1,word2,dp);
        else
        {
            return  dp[indx1][indx2]= 1+min(solve(indx1-1,indx2,word1,word2,dp),min(solve(indx1,indx2-1,word1,word2,dp),solve(indx1-1,indx2-1,word1,word2,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,word1,word2,dp);
    }
};