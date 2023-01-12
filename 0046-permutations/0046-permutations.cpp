class Solution {
public:
    void helper(vector<int>&v, vector<vector<int>>&ans,vector<int>& nums,vector<int>&vis)
    {
        if(v.size()==nums.size())
        {
            ans.push_back(v);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                v.push_back(nums[i]);
                helper(v,ans,nums,vis);
                vis[i]=0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        vector<int>vis(nums.size(),0);
        helper(v,ans,nums,vis);
        return ans;
    }
};