class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        int cnt=0;
        for(int i=0;i<t.length();i++)
        {
            if(m.find(t[i])==m.end())
            {
                cnt++;
            }
            else
            {
                m[t[i]]--;
                if(m[t[i]]==0) m.erase(t[i]);
            }
        }
        return cnt;
    }
};