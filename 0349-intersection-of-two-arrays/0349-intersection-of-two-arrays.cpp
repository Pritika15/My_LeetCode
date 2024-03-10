class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        set<int>s;
        for(int i=0;i<nums1.size();i++)
        {
            s.insert(nums1[i]);
        }
        set<int>s1;
        for(int i=0;i<nums2.size();i++)
        {
            s1.insert(nums2[i]);
        }
        
        for(auto x:s)
        {
            if(s1.find(x)!=s1.end())
            {
                ans.push_back(x);
            }
        }
       
        return ans;
    }
};