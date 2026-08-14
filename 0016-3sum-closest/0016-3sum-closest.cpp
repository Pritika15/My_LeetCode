class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mini = 0;
        int mini_diff = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int c = i, a = i + 1, b = n - 1;
            while (a < b) {
                int sum = nums[a]+nums[b]+nums[c];
                int current_diff = abs(target - sum);
                if (current_diff < mini_diff) {
                    mini_diff = current_diff;
                    mini = sum;
                }
                if(sum < target) a++;
                else b--;
            }
        }
        return mini;
    }
};