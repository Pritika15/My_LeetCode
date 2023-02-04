class Solution {
public:
    void helper(vector<vector<int>>&ans, vector<int>&a,vector<int>nums,vector<int>&vis)
    {
        if(a.size()==nums.size())
        {
            ans.push_back(a);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i]==0)
            {
                a.push_back(nums[i]);
                vis[i]=1;
                helper(ans,a,nums,vis);
                vis[i]=0;
                a.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int>a;
        vector<int>vis(n,0);
        helper(ans,a,nums,vis);
        
        return ans;
    }
};