class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    vector<int>ans;
    unordered_map<int,int>m;
    int n=nums.size();
    int v=floor(n/3);
    for(int i=0;i<n;i++)
    {
        m[nums[i]]++;
    }
    for(auto itr:m)
    {
        if(itr.second>v) ans.push_back(itr.first);
    }
    return ans;
    }
};