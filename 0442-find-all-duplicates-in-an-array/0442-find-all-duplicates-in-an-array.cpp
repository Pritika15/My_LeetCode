class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int x=nums[0];
        for(int i =1;i< nums.size();i++)
        {
            if(nums[i]==x)
            {
                ans.push_back(nums[i]);
                
            } 
            else
            {
                x=nums[i];
            }
        }
        return ans;
    }
};