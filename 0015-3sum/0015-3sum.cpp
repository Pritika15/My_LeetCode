class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>>s1;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++)
        {
            int c = i, a= i+1,b=n-1;
            while(a<b)
            {
                if(nums[a]+nums[b]+nums[c]==0){
                    s1.insert({nums[c],nums[a],nums[b]});
                    a++;
                }
                else if( nums[a]+nums[b] + nums[c] > 0) b--;
                else a++;
            }
        }
        for( const auto ele : s1)
        {
            ans.push_back(ele);
        }
        return ans;
        
    }
};