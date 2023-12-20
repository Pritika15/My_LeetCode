class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int IniMoney=money;
        sort(prices.begin(),prices.end());
        int cnt=2;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<=money && cnt>0)
            {
                cnt--;
                money=money-prices[i];
                if(cnt==0) break;
                
            }
        }
        if(cnt>0) return IniMoney;
        return money;
    }
};