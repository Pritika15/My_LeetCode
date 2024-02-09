class Solution {
public:
    vector<int>ans;
    void solve(vector<int>& nums,int indx,int prev, vector<int>&temp,vector<int>&dp)
    {
//         base condn:
        if(indx>= nums.size())
        {
            if(temp.size()>ans.size()) ans=temp;
            return;
        }
//         take and not take part
//         take that element into my subset
        if(nums[indx]%prev==0 && (int) temp.size()>dp[indx])
        {
           dp[indx]=temp.size();
            temp.push_back(nums[indx]);
            solve(nums,indx+1,nums[indx],temp,dp);
            temp.pop_back();
        }
//         no take condn
        solve(nums,indx+1,prev,temp,dp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
//         step 1:
        sort(nums.begin(),nums.end());
//         step : recursion
        vector<int>temp;
        int n=nums.size();
        vector<int>dp(n,-1);
//         store the longesr diuvsible subset at that index.
        solve(nums,0,1,temp,dp);
//         prev=1; ---? 1 is the multiple for every number in the number system
        
        return ans;
    }
};