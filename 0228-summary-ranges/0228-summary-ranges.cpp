class Solution {
public:
    void AddToVec(vector<int>&v, vector<string>&ans)
    {
        int n=v.size();
        string tt;
        if(v.size()==1)
        {
            tt=to_string(v[0]);
        }
        else
        {
            tt=to_string(v[0])+"-"+">"+to_string(v[n-1]);
        }
        
        ans.push_back(tt);
    }
    vector<string> summaryRanges(vector<int>& nums) {
      int n=nums.size();
      vector<int>v;
        vector<string>ans;
        if(nums.size()==1)
        {
            string t=to_string(nums[0]);
            ans.push_back(t);
        }
        else
        {
            for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(nums[i]==nums[i+1]-1) v.push_back(nums[i]);
                else
                {
                    string t=to_string(nums[i]);
                    ans.push_back(t);
                }
                    
            }
            else if(i==n-1)
            {
                
                v.push_back(nums[i]);
                AddToVec(v,ans);
                  // v.clear();
                 
                
            }
            else if(nums[i]==nums[i+1]-1)
            {
                v.push_back(nums[i]);
            }
            else if(nums[i]==nums[i-1]+1)
            {
                if(nums[i]!=nums[i+1]-1)
                {
                    v.push_back(nums[i]);
                    AddToVec(v,ans);
                    v.clear();
                }
            }
            else
            {
                string t=to_string(nums[i]);
                ans.push_back(t);
            }
        }
        }
        
        return ans;
    }
};