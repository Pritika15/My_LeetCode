class Solution {
public:
    void sortColors(vector<int>& nums) {
        stack<int>s0;
        stack<int>s1;
        stack<int>s2;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                s0.push(nums[i]);
            else if(nums[i]==1)
                s1.push(nums[i]);
            else
                s2.push(nums[i]);
        }
        int i=0;
        while(!s0.empty()){
            int x=s0.top();
            nums[i++]=x;
            s0.pop();
        }
         while(!s1.empty()){
            int x=s1.top();
            nums[i++]=x;
            s1.pop();
        }
         while(!s2.empty()){
            int x=s2.top();
            nums[i++]=x;
            s2.pop();
        }
       
    }
};