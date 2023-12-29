class Solution {
public:
    int n;
    int dp[305][15];
    int dfs(int i,int d,vector <int> &jd)
    {
        if(i==n && d==0) //end of our search with all elements covered and 0 days remaining
            return 0;
        if(i==n || d==0 || n-i<d) //if elements are remaining or elements are used up but days are remaining
            return 1e9;
        if(dp[i][d]!=-1) //if already seen this state,return it
            return dp[i][d];
        int ans=1e9;
        int maxele=-1e9;
        for(int j=i;j<n;j++)
        {   
            maxele=max(maxele,jd[j]); //max element from i to j
            ans=min(ans,maxele+dfs(j+1,d-1,jd)); //minimum of all possible answers
        }
        dp[i][d]=ans;
        return ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n=jobDifficulty.size();
        if(n<d)       //not possible
            return -1;
        memset(dp,-1,sizeof(dp));
        int ans= dfs(0,d,jobDifficulty);
        return ans;
    }
};