class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        stack<int>st;
        unordered_map<int,int>map;
        for(int i=0;i<nums2.size();i++)
        {
            int ele=nums2[i];
            while(!st.empty() && ele>st.top())
            {
                map[st.top()]=ele;
                st.pop();
            }
            st.push(ele);
        }
        while(!st.empty())
        {
            map[st.top()]=-1;
            st.pop();
        }
        for(int i=0;i<nums1.size();i++)
        {
            if(map.find(nums1[i])!=map.end())
            {
                ans.push_back(map[nums1[i]]);
            }
        }
        return ans;
    }
};