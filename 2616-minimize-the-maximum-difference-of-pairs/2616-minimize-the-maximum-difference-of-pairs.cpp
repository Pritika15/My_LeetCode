class Solution {
public:
    bool ifPossible(vector<int>& nums, int p,int n, int diff)
    {
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]<=diff)
            {
                p--;
                i++;
            }
        }
        return p<=0;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums[n-1]-nums[0];
        int ans=right;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(ifPossible(nums,p,n,mid))
            {
                 ans=mid;
                 right=mid-1;
                
            }
            else
            {
                left=mid+1;
            }
               
        }
        return ans;
    }
};