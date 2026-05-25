class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int maxProfit = 0;
        for(int i =0;i<n;i++)
        {
            if(prices[i]<mini){
                mini = min(mini,prices[i]);
            } 
            maxProfit = max(maxProfit,prices[i]-mini);

        }
        return maxProfit;

    }
};