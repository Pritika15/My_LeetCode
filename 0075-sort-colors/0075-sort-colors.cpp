class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        for(int i=0;i<n;i++)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};