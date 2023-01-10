class Solution {
public:
    void helper(int index,vector<int>& nums,set<vector<int>>&s,vector<int>&v)
    {
        
        if(index==nums.size())
        {
            s.insert(v);
            return;
        }
        v.push_back(nums[index]);
        helper(index+1,nums,s,v);
        v.pop_back();
        helper(index+1,nums,s,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //cout<<nums.size()-1;
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        vector<int>v;
        helper(0,nums,s,v);
         vector<vector<int>> ans(s.begin(),s.end());
        // for(auto x:s)
        // {
        //     ans.push_back(x);
        // }
        
        return ans;
    }
};