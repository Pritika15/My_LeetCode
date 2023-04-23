#define mod 1000000007
#define ll long long int 
ll dp[100001];
ll solve(string &s,ll k,int pos)
{
    if(pos==s.length()) return 1;
    if(dp[pos]!=-1) return dp[pos];
    
    ll ans=0;

    ll x=0;
    for(int i=pos;i<s.length();i++)
    {
        x=(x*10)+(s[i]-'0');
        if(x<=k && x>=1ll)
        {
            ans=(ans+solve(s,k,i+1))%mod;
        }
        else break;
    }
    return dp[pos]=ans;
}
class Solution {
public:
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,k,0);
        
    }
};