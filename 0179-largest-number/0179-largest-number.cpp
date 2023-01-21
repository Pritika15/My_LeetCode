class Solution {
public:
   static bool cmp(string a, string b)
    {
        if(a+b>b+a) return true;
        
        return false;
    }
    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string>numsStr;
        for(auto x:nums)
        {
            numsStr.push_back(to_string(x));
        }
        sort(numsStr.begin(),numsStr.end(),cmp);
        for(int i=0;i<numsStr.size();i++)
        {
            ans+=numsStr[i];
        }
        int i=0;
        while(i<ans.length()-1 && ans[i]=='0')
        {
            
                i++;
        }
        return ans.substr(i);
    }
};