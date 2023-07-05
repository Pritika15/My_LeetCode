class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int head=0,tail=0,cnt=0;
        while(head<nums.size())
        {
            if(nums[head]==0) cnt++;
            
            while(cnt>1)
            {
                if(nums[tail]==0) cnt--;
                tail++;
            }
            
            ans=max(ans,head-tail);
            head++;
            
        }
        return ans;
    }
};