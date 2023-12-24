class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        vector<int>pos;
        vector<int>neg;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }
        int n=pos.size();
        int j1=0,j2=0;
        int cnt=0;
        while(j1<n && j2<n)
        {
            if(cnt%2==0)
            {ans.push_back(pos[j1]);
             j1++;
            }
            else
            {
                ans.push_back(neg[j2]);
                j2++;
                
            }
            cnt++;
        }
        if(j2<n)
        {
            for(j2;j2<n;j2++) ans.push_back(neg[j2]);
        }
        // if()
        return ans;
    }
};