class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word="";
        vector<string>v;
        for(int i=0;i<=s.length();i++)
        {
            if(s[i]==' '|| i==s.length())
            {
                v.push_back(word);
                word="";
            }
            else
            {
                word.push_back(s[i]);
            }
        }
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        if(pattern.length()!=v.size()) return false;
        unordered_map<char,string>m;
        set<string>st;
        for(int i=0;i<pattern.length();i++)
        {
            if(m.find(pattern[i])!=m.end())
            {
                if(m[pattern[i]] != v[i]) return false;
            }
            else
            {
                if(st.count(v[i])>0) return false;
            }
            m[pattern[i]]=v[i];
            st.insert(v[i]);
        }
        return true;
    }
};
