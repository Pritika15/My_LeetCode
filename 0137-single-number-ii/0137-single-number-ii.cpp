class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto itr:m)
        {
            if(itr.second==1)
            {
                ans= itr.first;
                break;
            }
        }
        return ans;
    }
};