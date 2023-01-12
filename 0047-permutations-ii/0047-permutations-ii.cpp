class Solution {
public:
    void helper(int index,vector<int>& nums,set<vector<int>>&s)
    {
        if(index==nums.size())
        {
            s.insert(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            helper(index+1,nums,s);
             swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>s;
        helper(0,nums,s);
        vector<vector<int>>ans;
        for(auto x:s)
            ans.push_back(x);
        return ans;
    }
};