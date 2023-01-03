class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int take=0;
        int notTake=0;
        vector<int>count(10001);
       // vector<int>dp(10001,-1);
        for(auto x:nums)count[x]++;
        
        
        for(int i=0;i<count.size();i++)
        {
           // if(dp[i]!= -1)return dp[i];
            int newTake=notTake+count[i]*i;
            int newNottake=max(take,notTake);
            
            take=newTake;
            notTake=newNottake;
        }
        return  max(take,notTake);
    }
};