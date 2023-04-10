class Solution {
public:
    void solve(int indx,vector<vector<int>>&ans,vector<int>& nums)
    {
        if(indx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=indx;i<nums.size();i++)
        {
            swap(nums[indx],nums[i]);
            solve(indx+1,ans,nums);
             swap(nums[indx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        
        solve(0,ans,nums);
        return ans;
    }
};