class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxiProf=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int currProf=prices[i]-mini;
            maxiProf=max(maxiProf,currProf);
            mini=min(mini,prices[i]);
        }
        return maxiProf;
    }
};