class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        map<int,int> freq;
        int max = 0;
        for(int i = 0; i<n; i++)
        {
            if(max<nums[i]) max = nums[i];
            freq[nums[i]]++;
        }
        if(n<max+1 || n>max+1) return false;
        if(freq[max]<2 || (freq.size()==1 & n>2)) return false;
        for(auto ptr = freq.begin(); ptr!=prev(freq.end());++ptr)
        {
            if(ptr->second>1) return false;
        }
        return true;
    }
};