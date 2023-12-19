class Solution {
public:
    int solve(int i, int j,string s, string t,vector<vector<int>>&dp )
    {
        if(j<0)
        {
            // j=t.length()-1;
            return 1;
        }
        if(i<0)
        {
            if(j<0) return 1;
            else return 0;
            
        }
        if(dp[i][j]!= -1)return dp[i][j];
        // int take=0,notTake=0;
        if(s[i]==t[j]) return dp[i][j]=solve(i-1,j-1,s,t,dp)+solve(i-1,j,s,t,dp);
        else return dp[i][j]=solve(i-1,j,s,t,dp);
        
         
    }
    int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,s,t,dp);
    }
};