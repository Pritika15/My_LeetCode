class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans= -1;
        int i=0;
        for(i;i<nums.size();i++)
        {
            if(i!=nums[i])
            {
                ans=i;
                break;
                
            }
                
            
                
        }
        if(ans== -1)
        {
            ans=i;
        }
        return ans;
    }
};