class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set <vector<int>>s;
            
        int n=nums.size();
       
        sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++)
       {
           int j=i+1;
           int k=n-1;
           while(j<k)
           {
               int sum=nums[i]+nums[j]+nums[k];
               if(sum==0)
               {
                   s.insert({nums[i],nums[j],nums[k]});
                   j++;
                   k--;
               }
               else if(sum>0)
               {
                   k--;
               }
               else
               {
                   j++;
               }
           }
       }
        for(auto it:s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};