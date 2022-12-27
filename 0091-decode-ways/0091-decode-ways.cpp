class Solution {
public:
    int helper(int index,string s,vector<int>&dp)
    {
        if(index>=s.size()) return 1;
        else if(s[index]=='0') return 0;
        else if(index==s.size()-1) return 1;
        if(dp[index]!= -1) return dp[index];
        else if(s[index]=='1'|| (s[index]=='2' && (s[index+1]>=48 && s[index+1]<=54)))
            return dp[index]= helper(index+1,s,dp)+helper(index+2,s,dp);
        else return dp[index]= helper(index+1,s,dp);
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return helper(0,s,dp);
    }
};