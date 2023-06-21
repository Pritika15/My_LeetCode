class Solution {
public:
    long long solve(vector<int>& nums, vector<int>& cost, long long median)
    {
        long long t=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            t=t+abs(median-nums[i])*cost[i];
        }
        return t;
        
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans=0;
        long long frq=0;
        long long median;
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++)
        {
            frq+=v[i].second;
        }
        
        int i=0;
        while(ans<((frq+1)/2) && i<nums.size())
        {
            ans+=v[i].second;
            median=v[i].first;
            i++;
        }
        return solve(nums,cost,median);
    }
};