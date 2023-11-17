class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int res = INT_MIN;
    sort(begin(nums), end(nums));
    for (auto i = 0; i < nums.size() / 2; ++i)
        res = max(res, nums[i] + nums[nums.size() - i - 1]);
    return res;
    }
};