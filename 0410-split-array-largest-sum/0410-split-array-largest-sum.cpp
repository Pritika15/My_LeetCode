class Solution {
public:
bool isPossible(const vector<int>& nums, int k, long long maxSum) {
    int count = 1; // Start with 1 subarray
    long long currSum = 0;

    for (int num : nums) {
        if (currSum + num > maxSum) {
            count++;        // Need a new subarray
            currSum = num;  // Start new subarray with 'num'
        } else {
            currSum += num;
        }
    }

    return count <= k; // Return true if we used <= k subarrays
}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sumval = 0;
        int maxEle = 0;

        for(int i=0;i<n;i++)
        {
            maxEle = max(maxEle,nums[i]);
            sumval+=nums[i];
        }

        int left = maxEle, right = sumval;

        while(left<right)
        {
            int mid = (left+right)/2;
            if(isPossible(nums,k,mid)) right= mid;
            else left = mid+1;
        }
        return left;
        
    }
};