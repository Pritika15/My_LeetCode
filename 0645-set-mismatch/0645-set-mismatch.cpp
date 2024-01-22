class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int>s;
        int missing,duplicate;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                duplicate=nums[i];
            }
            s.insert(nums[i]);
        }
        
        for(int i=1;i<=nums.size();i++)
        {
            if(s.find(i)==s.end())
            {
                missing=i;
            }
        }
        
        return {duplicate,missing};
    }
};