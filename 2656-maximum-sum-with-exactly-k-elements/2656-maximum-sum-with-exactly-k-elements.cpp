class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        int ans=0;
        while(k!=0)
        {
            int x=nums[0];
            ans+=x;
            nums[0]=x+1;
            k--;
        }
        return ans;
    }
};