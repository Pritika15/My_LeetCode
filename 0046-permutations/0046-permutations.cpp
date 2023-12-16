class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>& nums,vector<int>&v,vector<int>&marked)
    {
        if(v.size()==nums.size())
        {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!marked[i])
            {
                v.push_back(nums[i]);
                marked[i]=1;
                solve(ans,nums,v,marked);
                v.pop_back();
                marked[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>v;
        vector<int>marked(n,0);
        
        solve(ans,nums,v,marked);
        return ans;
    }
};