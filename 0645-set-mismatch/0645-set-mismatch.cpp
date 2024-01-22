class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        
        int xorAll=0,xorArr=0;
        
        for(int i=1;i<=n;i++)
        {
            xorAll^=i;
        }
        
        for(int i=0;i<n;i++)
        {
            xorArr^=nums[i];
        }
        
        int xorRes=xorAll^xorArr;
        
        int rightmostSetBit=xorRes& -xorRes;
        
        int xorSet=0;
        int xorNotSet=0;
        
        for(int i=1;i<=n;i++)
        {
            if(i&rightmostSetBit)
            {
                xorSet^=i;
            }
            else
            {
                xorNotSet^=i;
            }
        }
        
        for(auto num:nums)
        {
            if(num & rightmostSetBit)
            {
                 xorSet^=num;
            }
            else
            {
                xorNotSet^=num;
            }
        }
        
        for(int num:nums)
        {
            if(num==xorSet)
            {
                return {xorSet,xorNotSet};
            }
        }
        return {xorNotSet,xorSet};
    }
};