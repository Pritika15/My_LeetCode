class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int ans;
        for(auto x:m)
        {
            if(x.second==1)
            {
                ans=x.first;
                break;
            }
        }
        return ans;
    }
};