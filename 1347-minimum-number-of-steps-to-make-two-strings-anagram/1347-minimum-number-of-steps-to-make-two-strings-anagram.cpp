class Solution {
public:
    int minSteps(string s, string t) {
        int cnt=0;
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        
        for(int i=0;i<t.length();i++)
        {
            if(m.find(t[i])==m.end())
            {
                cnt++;
            }
            else
            {
                m[t[i]]--;
                if(m[t[i]]==0)
                {
                    m.erase(t[i]);
                }
               
            }
        }
        // cout<<cnt;
        return cnt;
    }
};