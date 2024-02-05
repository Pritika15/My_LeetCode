class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>v(26,0);
        for(int i=0;i<s.length();i++)
        {
            v[s[i]-'a']++;
        }
        int ans= -1;
        for(int i=0;i<s.length();i++)
        {
            if(v[s[i]-'a']==1)
            {
                ans= i;
                break;
            }
        }
        return ans;
    }
};