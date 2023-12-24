class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxiOne=0;
        int cntOne=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1) cntOne++;
            else cntOne=0;
            maxiOne=max(maxiOne,cntOne);
        }
        return maxiOne;
    }
};