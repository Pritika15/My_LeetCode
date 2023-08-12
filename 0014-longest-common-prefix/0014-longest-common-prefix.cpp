class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int n=strs.size();
        if(n==1) return strs[0];
        sort(strs.begin(),strs.end());
        string s1=strs[0];
        string s2=strs[n-1];
        int len=min(s1.length(),s2.length());
        for(int i=0;i<len;i++)
        {
            if(s1[i]==s2[i]) ans+=s1[i];
            else
            {
                break;
            }
        }
        if(ans.size()==0) return "";
        return ans;
    }
};