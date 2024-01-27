class Solution {
private:
    const int mod=int(1e9+7);
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        //base case
        for(int N=0;N<=n;++N) dp[N][0]=1;
        for(int N=1;N<=n;++N) {
            for(int K=0;K<=k;++K) {
                int ans=0;
                for(int i=0;i<min(N,K+1);++i) {
                    ans+=dp[N-1][K-i];
                    ans%=mod;
                }
                dp[N][K]=ans;
            }
        }
        return dp[n][k];
    }
};