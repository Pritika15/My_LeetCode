class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>  ans;
//         step 1: sort the given arr
        sort(nums.begin(),nums.end());
//         step2 : check for the 3 consecutive places
        for(int i=2;i<nums.size();i=i+3)
        {
            if(nums[i]-nums[i-2]>k) return {};
            ans.push_back({nums[i-2],nums[i-1],nums[i]});
        }
        return ans;
    }
};