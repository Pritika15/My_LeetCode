class Solution {
public:
    void helper(int index,vector<int>& nums,vector<vector<int>>&ans,vector<int>&v)
    {
        //vector<vector<int>>ans;
        
        if(index==nums.size())
        {
            // for(int i=0;i<v.size();i++)
            //     cout<<v[i]<<" ";
            // cout<<endl;
            ans.push_back(v);
            return ;
        }
        v.push_back(nums[index]);
        // for(int i=0;i<v.size();i++)
        //         cout<<v[i]<<" ";
        helper(index+1,nums,ans,v);
        v.pop_back();
        helper(index+1,nums,ans,v);
        
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>v;
         helper(0,nums,ans,v);
        return ans;
    }
};