class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    vector<int>ans;
    int num1=INT_MIN, num2=INT_MIN;
    int c1=0,c2=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==num1)c1++;
        else if(nums[i]==num2)c2++;
        else if(c1==0)
        {
            num1=nums[i];
            c1=1;
            
         }
        else if(c2==0)
        {
            num2=nums[i];
            c2=1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    int CNT1=0, CNT2=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==num1) CNT1++;
        if(nums[i]==num2) CNT2++;
        
    }
    int Check=floor(nums.size()/3);
    if(CNT1>Check) ans.push_back(num1);
    if(CNT2>Check) ans.push_back(num2);
    return ans;
    }
};