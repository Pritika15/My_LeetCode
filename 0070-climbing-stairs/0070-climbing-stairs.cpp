class Solution {
public:
    int climbStairs(int n) {
        int prevlast=1; //dp[0]
        int prev=1; //dp[1];
        
        for(int i=2;i<=n;i++)
        {
            int curr=prevlast+prev;
            prevlast=prev;
            prev=curr;
        }
        return prev;
    }
};