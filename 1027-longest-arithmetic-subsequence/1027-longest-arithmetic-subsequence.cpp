class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int ans=0;
        unordered_map<int,int>m[n+1];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[i]-nums[j];
                int cnt=1;
                if(m[j].count(diff)) cnt=m[j][diff];
                m[i][diff]=1+cnt;
                ans=max(ans,m[i][diff]);
            }
        }
        return ans;
    }
};