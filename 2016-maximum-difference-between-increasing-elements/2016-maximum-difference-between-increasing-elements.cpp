class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int MaxDiff=-1;
        int mini=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int currDiff=nums[i]-mini;
            MaxDiff=max(MaxDiff,currDiff);
            mini=min(mini,nums[i]);
        }
        if(MaxDiff!=0) return MaxDiff;
        else return -1;
    }
};