class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int currSum1=0;
        int maxi1=INT_MIN;
        for(int i=0;i<n;i++)
        {
            currSum1+=nums[i];
            if(currSum1>maxi1) maxi1=currSum1;
            if(currSum1<0) currSum1=0;
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=-1*nums[i];
        }
        int currSum=0;
        int maxi=INT_MIN;
        int sum=0;
        int InvAns;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            currSum+=nums[i];
            if(currSum>maxi) maxi=currSum;
            if(currSum<0) currSum=0;
        }
        InvAns= -1*(sum-maxi);
        if(maxi1<0)
            return maxi1;
        else
        return max(maxi1,InvAns);
    }
};