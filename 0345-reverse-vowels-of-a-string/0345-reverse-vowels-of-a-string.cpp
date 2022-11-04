class Solution {
public:
    string reverseVowels(string s) {
        string ss="";
        queue<int>q;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a'|| s[i]=='A'||s[i]=='e'|| s[i]=='E'||s[i]=='i' || s[i]=='I'||s[i]=='o'|| s[i]=='O'||s[i]=='u'|| s[i]=='U')
            {
                ss.push_back(s[i]);
                q.push(i);
            }
        }
        reverse(ss.begin(),ss.end());
        int i=0;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            s[t]=ss[i++];
        }
        return s;
    }
};