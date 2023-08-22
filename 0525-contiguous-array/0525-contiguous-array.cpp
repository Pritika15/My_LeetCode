class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int>m;
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) sum=sum-1;
            else sum=sum+1;
            if(sum==0)
            {
                maxi=max(maxi,i+1);
            }
            if(m.find(sum)==m.end())
            {
                m[sum]=i;
            }
            else
            {
                maxi=max(maxi,i-m[sum]);
            }
        }
        return maxi;
    }
};