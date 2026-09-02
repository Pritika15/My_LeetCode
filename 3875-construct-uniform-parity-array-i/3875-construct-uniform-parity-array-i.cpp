class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool ans = false;
        int n = nums1.size();
        int cntEven=0, cntOdd=0;

        for(int i =0;i<n;i++)
        {
            if(nums1[i]%2==0)cntEven++;
            else cntOdd++;
        }

        if(cntEven==n || cntOdd==n) return true;

        vector<int>nums(n);

        for(int i =1;i<n;i++)
        {
            nums.push_back(nums1[i-1]-nums[i]);
        }

        cntEven=0, cntOdd=0;

        for(int i =0;i<n;i++)
        {
            if(nums[i]%2==0)cntEven++;
            else cntOdd++;
        }

        if(cntEven==n || cntOdd==n) return true;

        return ans;


    }
};