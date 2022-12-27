class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1,t1;
        int size1=s.length();
        int size2=t.length();
        for(int i=0;i<size1;i++)
        {
            if(s[i]=='#' && !s1.empty())
            {
                s1.pop();
            }
            else if(s[i]!='#')
            {
                s1.push(s[i]);
            }
        }
         for(int i=0;i<size2;i++)
        {
            if(t[i]=='#' && !t1.empty())
            {
                t1.pop();
            }
            else if(t[i]!='#')
            {
                t1.push(t[i]);
            }
        }
        string str1,str2;
        while(!s1.empty())
        {
            char a =s1.top();
            s1.pop();
            str1.push_back(a);
        }
         while(!t1.empty())
        {
            char a =t1.top();
            t1.pop();
            str2.push_back(a);
        }
       return str1==str2;
    }
};