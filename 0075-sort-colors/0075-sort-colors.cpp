class Solution {
public:
    void sortColors(vector<int>& nums) {
        stack<int>s1,s2,s3;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) s1.push(nums[i]);
            else if(nums[i]==1) s2.push(nums[i]);
            else s3.push(nums[i]);
        }
        int i =0;
        while(!s1.empty()&&i<n)
        {
            nums[i]=s1.top();
            s1.pop();
            i++;
        }
        while(!s2.empty()&&i<n)
        {
            nums[i]=s2.top();
            s2.pop();
            i++;
        }
        while(!s3.empty()&&i<n)
        {
            nums[i]=s3.top();
            s3.pop();
            i++;
        }
    }
};