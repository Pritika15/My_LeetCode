class Solution {
public:
    int solve(int index,vector<int>& days, vector<int>& costs,vector<int>&dp)
    {
        if(index>=days.size())
            return 0;
        
        if(dp[index]!= -1) return dp[index];
        int op1=costs[0]+solve(index+1,days,costs,dp);
        
        int i;
        for(i=index;i<days.size() && days[i]<days[index]+7;i++);
        
        int op2=costs[1]+solve(i,days,costs,dp);
        for(i=index;i<days.size() && days[i]<days[index]+30;i++);
        
        int op3=costs[2]+solve(i,days,costs,dp);
        
        return dp[index]=min(op1,min(op2,op3));
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return solve(0,days,costs,dp);
    }
};