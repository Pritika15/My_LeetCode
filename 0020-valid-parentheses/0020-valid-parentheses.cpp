class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char>s1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' ||s[i]=='[')
            {
                s1.push(s[i]);
            }
            else if((s[i]==')' || s[i]==']' || s[i]=='}' ) && s1.empty())
            {
                return false;
            }
            else
            {
                if(!s1.empty())
                {
                    char temp=s1.top();
                    s1.pop();
                    if(s[i]==')')
                    {
                        if(temp=='[' || temp=='{')
                            return false;
                    }
                    else if(s[i]==']')
                    {
                        if(temp=='(' || temp=='{')
                            return false;
                    }
                    else
                    {
                        if(temp=='(' || temp=='[')
                            return false;
                    }
                }
            }
        }
        if(!s1.empty()) return false;
        
        return true;
    }
};