class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini=1e5+1;
       int head=0,tail=0;
        int n=nums.size();
        int sum=0;
        while(head<n)
        {
            sum=sum+nums[head];
            // cout<<sum<<" ";
            if(sum>=target)
            {
                
                while(sum>=target)
                {
                    mini=min(mini,head-tail+1);
                    sum-=nums[tail];
                    tail++;
                }
        
            }
            head++;
        }
        if(mini==1e5+1) return 0;
        return mini;
    }
};