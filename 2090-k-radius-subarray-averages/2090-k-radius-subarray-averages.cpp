class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        long long int prefix[n], suffix[n];
        
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;--i)
        {
            suffix[i]=suffix[i+1]+nums[i];
        }
        
        for(int i=0;i<n;i++)
        {
            if(i<k || n-i-1 <k) ans.push_back(-1);
            else
            {
                long long int sum=( long long int)((suffix[i-k]-suffix[i])+(prefix[i+k]-prefix[i]+nums[i]));
                sum=sum/(2*k+1);
                ans.push_back(sum);
            }
        }
        return ans;
    }
};