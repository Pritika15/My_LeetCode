class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int index=abs(nums[i])-1;
            nums[index]= -nums[index];
            if(nums[index]>0)
            {
                ans.push_back(index+1);
            }
        }
        return ans;
    }
};