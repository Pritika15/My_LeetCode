class Solution {
public:
    void helper(int index,vector<int>& nums,set<vector<int>>&s,vector<int>&v)
    {
        if(index==nums.size())
        {
            if(v.size()>1)
            {
                 s.insert(v);
            }
           
            return;
        }
        if(v.size()==0||nums[index]>=v[v.size()-1])
        {
             v.push_back(nums[index]);
             helper(index+1,nums,s,v);
            v.pop_back();
        }
           
        
       
        helper(index+1,nums,s,v);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        vector<int>v;
        helper(0,nums,s,v);
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};