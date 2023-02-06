class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>temp1;
        vector<int>temp2;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(n!=0)
            {
                temp1.push_back(nums[i]);
                n--;
            }
            else
            {
                temp2.push_back(nums[i]);
            }
        }
        for(int i=0;i<temp1.size();i++)
        {
            ans.push_back(temp1[i]);
            ans.push_back(temp2[i]);
        }
        return ans;
    }
};