class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l, int h)
    {
        if(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(nums[mid]==target) return mid;
            
            if(nums[mid]>target)
                return binarySearch(nums,target,l,mid-1);
            return binarySearch(nums,target,mid+1,h);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
       int n=nums.size();
        return binarySearch(nums,target,0,n-1);
        
    }
};