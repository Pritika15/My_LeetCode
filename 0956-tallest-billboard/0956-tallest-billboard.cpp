const int offset=5000;
class Solution {
public:
    int dp[21][2*offset+1];
    int solve(int indx,int diff,vector<int>& rods,int n)
    {
        if(indx==n)
        {
            if(diff==0) return 0;
            else return INT_MIN;
        }
        if(dp[indx][diff+offset]!=-1) return dp[indx][diff+offset];
        
        int opt1=solve(indx+1,diff,rods,n);
        int opt2=rods[indx]+solve(indx+1,diff+rods[indx],rods,n);
        int opt3=solve(indx+1,diff-rods[indx],rods,n);
        
        return dp[indx][diff+offset]=max(opt1,max(opt2,opt3));

    }
    int tallestBillboard(vector<int>& rods) {
        
        memset(dp,-1,sizeof(dp));
        int n=rods.size();
        return solve(0,0,rods,n);
        
    }
};