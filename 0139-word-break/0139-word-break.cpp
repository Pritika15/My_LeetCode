class Solution {
public:
    bool solve(int indx,string s,unordered_map<string,int>m,vector<int>&dp)
    {
        if(indx==s.size()) return 1;
        if(dp[indx]!= -1) return dp[indx];
        string var;
        for(int i=indx;i<s.size();i++)
        {
            var+=s[i];
            if(m.find(var)!=m.end())
            {
               if(solve(i+1,s,m,dp)) return dp[indx]=1;
            }
            // else if(m.find(var)==m.end() && i==temp.size()-1) return 0;
            
        }
        return dp[indx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>m;
        int n=s.length();
        vector<int>dp(n,-1);
        for(int i=0;i<wordDict.size();i++)
        {
            m[wordDict[i]]++;
        }
       return solve(0,s,m,dp);
    }
};