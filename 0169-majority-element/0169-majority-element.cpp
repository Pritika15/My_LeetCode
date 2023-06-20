class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int>m;
        int ans;
        int Check=floor(nums.size()/2);
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto itr:m)
        {
            if(itr.second>Check)
            {
                ans=itr.first;
                break;
            }
        }
        return ans;
    }
};